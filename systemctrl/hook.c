#include <pspkernel.h>
#include <string.h>

#include <systemctrl_me.h>

SceLibraryStubTable *sctrlFindImportLib(SceModule *mod, char *library)
{
	if(mod == NULL)
	{
		return NULL;
	}

	void *stubTab = mod->stub_top;
	int stubLen = mod->stub_size;
	int i = 0;

	while(i < stubLen)
	{
		SceLibraryStubTable *pImp = (SceLibraryStubTable*)(stubTab + i);

		if((pImp->libname) && (strcmp(pImp->libname, library) == 0))
		{
			return pImp;
		}

		i += (pImp->len * 4);
	}

	return NULL;
}

u32 sctrlFindImportByNID(SceModule *mod, char *library, u32 nid)
{
	SceLibraryStubTable *pImp = sctrlFindImportLib(mod, library);

	if(pImp)
	{
		int i;

		for(i = 0; i < pImp->stubcount; i++)
		{
			if(pImp->nidtable[i] == nid)
			{
				return (u32) pImp->stubtable + 8 * i;
			}
		}
	}

	return 0;
}

int sctrlHookImportByNID(SceModule *mod, char *library, u32 nid, void *func)
{
	if(mod == NULL)
	{
		return -1;
	}

	void *addr = (void*)sctrlFindImportByNID(mod, library, nid);

	if (addr)
	{
		if(func == NULL)
		{
			_sw(0x03E00008, (u32)addr);
			_sw(0, (u32)(addr + 4));
		}
		else
		{
			if (((u32)addr & 0x80000000) == 0 && ((u32)func & 0x80000000) != 0)
			{
				u32 syscall_num;

				syscall_num = sceKernelQuerySystemCall(func);

				if(syscall_num == (u32)-1)
				{
					return -1;
				}

				_sw(0x03E00008, (u32)addr);
				_sw(((syscall_num << 6) | 12), (u32)(addr + 4));
			}
			else
			{
				_sw((0x08000000 | (((u32)(func) >> 2) & 0x03FFFFFF)), (u32)addr);
				_sw(0, (u32)(addr + 4));
			}
		}

		sceKernelDcacheWritebackInvalidateRange(addr, 8);
		sceKernelIcacheInvalidateRange(addr, 8);
	}

	return 0;
}

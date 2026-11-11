#include <pspsdk.h>
#include <pspkernel.h>

#include <string.h>

#include "main.h"

//#define CONFIG_MAGIC	0x4743454D
#define CONFIG_MAGIC	SECONFIG_MAGIC_LME

#define CONFIG_PATH "flashfat1:/config.me"
#define CONFIG_MINI_PATH "flashfat1:/vsh.me"

int sctrlSERstMiniConfigEx(VshConfig *config, int size)
{
	memset(config, 0, size);
	return size;
}

int sctrlSERstMiniConfig(VshConfig *config)
{
	return sctrlSERstMiniConfigEx(config, sizeof(VshConfig));
}

int sctrlSEGetMiniConfigEx(VshConfig *config, int size)
{
	int k1 = pspSdkSetK1(0);
	int ret;

	memset(config, 0, size);

	SceUID fd = sceIoOpen(CONFIG_MINI_PATH, PSP_O_RDONLY, 0644);
	if (fd >= 0)
	{
		ret = sceIoRead(fd, config, size);
		sceIoClose(fd);

		if (config->magic != MINI_MAGIC)
		{	
			ret = sctrlSERstMiniConfig(config);
		}
	}
	else
	{
		ret = sctrlSERstMiniConfig(config);
	}

	pspSdkSetK1(k1);

	return ret;
}

int sctrlSEGetMiniConfig(VshConfig *config)
{
	return sctrlSEGetMiniConfigEx(config, sizeof(VshConfig));
}

int sctrlSESetMiniConfigEx(VshConfig *config, int size)
{
	int k1 = pspSdkSetK1(0);
	int ret = -1;

	SceUID fd = sceIoOpen(CONFIG_MINI_PATH, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	if (fd >= 0)
	{
		config->magic = MINI_MAGIC;
		if (sceIoWrite(fd, config, size) == size)
		{
			ret = size;
		}

		sceIoClose(fd);
	}

	pspSdkSetK1(k1);

	return ret;
}

int sctrlSESetMiniConfig(VshConfig *config)
{
	return sctrlSESetMiniConfigEx(config, sizeof(VshConfig));
}

int sctrlSERstConfigEx(SEConfig *config, int size)
{
	memset(config, 0, size);

	config->lme.magic = CONFIG_MAGIC;
	config->lme.umdmode = MODE_NP9660;

#if PSP_MODEL != 0
	config->lme.usbcharge = 1;
	config->lme.iso_cache = 0;
	config->lme.high_memory = 1;
#endif

	config->lme.iso_cache_num = 4;
	config->lme.iso_cache_total_size = 20;

	return size;
}

int sctrlSERstConfig(SEConfig *config)
{
	return sctrlSERstConfigEx(config, sizeof(SEConfigLME));
}

int sctrlSEGetConfigEx(SEConfig *config, int size)
{
	int k1 = pspSdkSetK1(0);
	int ret;

	memset(config, 0, size);

	SceUID fd = sceIoOpen(CONFIG_PATH, PSP_O_RDONLY, 0644);
	if (fd >= 0)
	{
		ret = sceIoRead(fd, config, size);
		sceIoClose(fd);

		if (config->lme.magic != CONFIG_MAGIC )
		{	
			ret = sctrlSERstConfig(config);
		}
	}
	else
	{
		ret = sctrlSERstConfig(config);
	}

	pspSdkSetK1(k1);

	return ret;
}

int sctrlSEGetConfig(SEConfig *config)
{
	return sctrlSEGetConfigEx(config, sizeof(SEConfigLME));
}

int sctrlSESetConfigEx(SEConfig *config, int size)
{
	int k1 = pspSdkSetK1(0);
	int ret = -1;

	SceUID fd = sceIoOpen(CONFIG_PATH, PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	if (fd >= 0)
	{
		config->lme.magic = CONFIG_MAGIC;
		if (sceIoWrite(fd, config, size) == size)
		{
			ret = size;
		}

		sceIoClose(fd);
	}

	pspSdkSetK1(k1);

	return ret;
}

int sctrlSESetConfig(SEConfig *config)
{
	return sctrlSESetConfigEx(config, sizeof(SEConfigLME));
}
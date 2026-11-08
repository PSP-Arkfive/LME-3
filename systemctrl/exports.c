#include <pspmoduleexport.h>
#define NULL ((void *) 0)

extern int module_bootstart;
extern int module_info;
extern int module_sdk_version;
static const unsigned int __syslib_exports[6] __attribute__((section(".rodata.sceResident"))) = {
	0xD3744BE0,
	0xF01D73A7,
	0x11B97506,
	(unsigned int) &module_bootstart,
	(unsigned int) &module_info,
	(unsigned int) &module_sdk_version,
};

extern int kuKernelLoadModule;
extern int kuKernelLoadModuleWithApitype2;
extern int kuKernelInitApitype;
extern int kuKernelInitFileName;
extern int kuKernelBootFrom;
extern int kuKernelInitKeyConfig;
extern int kuKernelInitKeyConfig;
extern int kuKernelGetUserLevel;
extern int kuKernelSetDdrMemoryProtection;
extern int kuKernelGetModel;
static const unsigned int __KUBridge_exports[20] __attribute__((section(".rodata.sceResident"))) = {
	0x4C25EA72,
	0x1E9F0498,
	0x8E5A4057,
	0x1742445F,
	0x60DDB4AE,
	0x501E983D,
	0xB0B8824E,
	0xA2ABB6D3,
	0xC4AF12AB,
	0x24331850,
	(unsigned int) &kuKernelLoadModule,
	(unsigned int) &kuKernelLoadModuleWithApitype2,
	(unsigned int) &kuKernelInitApitype,
	(unsigned int) &kuKernelInitFileName,
	(unsigned int) &kuKernelBootFrom,
	(unsigned int) &kuKernelInitKeyConfig,
	(unsigned int) &kuKernelInitKeyConfig,
	(unsigned int) &kuKernelGetUserLevel,
	(unsigned int) &kuKernelSetDdrMemoryProtection,
	(unsigned int) &kuKernelGetModel,
};

extern int sctrlSESetMiniConfig;
extern int sctrlSESetMiniConfigEx;
extern int sctrlSEGetMiniConfig;
extern int sctrlSEGetMiniConfigEx;
extern int sctrlSERstMiniConfig;
extern int sctrlSERstMiniConfigEx;
static const unsigned int __MECtrl_exports[12] __attribute__((section(".rodata.sceResident"))) = {
	0xEA85C82C,
	0x27A0CE8A,
	0x0A2C56A2,
	0x1A0FB936,
	0xEDB7E6AC,
	0x78AE7B1D,
	(unsigned int) &sctrlSESetMiniConfig,
	(unsigned int) &sctrlSESetMiniConfigEx,
	(unsigned int) &sctrlSEGetMiniConfig,
	(unsigned int) &sctrlSEGetMiniConfigEx,
	(unsigned int) &sctrlSERstMiniConfig,
	(unsigned int) &sctrlSERstMiniConfigEx,
};

extern int sctrlKernelSetInitApitype;
extern int sctrlKernelSetInitFileName;
extern int sctrlKernelSetInitKeyConfig;
extern int sctrlKernelSetInitKeyConfig;
extern int sctrlKernelSetUserLevel;
extern int sctrlKernelSetDevkitVersion;
extern int sctrlHENIsSE;
extern int sctrlHENIsDevhook;
extern int sctrlHENGetVersion;
extern int sctrlHENFindDriver;
extern int sctrlHENFindFunction;
extern int sctrlHENSetMemory;
extern int sctrlSEGetVersion;
extern int sctrlKernelExitVSH;
extern int sctrlKernelLoadExecVSHDisc;
extern int sctrlKernelLoadExecVSHDiscUpdater;
extern int sctrlKernelLoadExecVSHMs1;
extern int sctrlKernelLoadExecVSHMs2;
extern int sctrlKernelLoadExecVSHMs3;
extern int sctrlKernelLoadExecVSHMs4;
extern int sctrlKernelLoadExecVSHWithApitype;
extern int sctrlKernelLoadExecVSHEf2;
extern int sctrlSESetConfig;
extern int sctrlSESetConfigEx;
extern int sctrlSEGetConfig;
extern int sctrlSEGetConfigEx;
extern int sctrlSERstConfig;
extern int sctrlSERstConfigEx;
extern int sctrlHENSetStartModuleHandler;
extern int sctrlSEMountUmdFromFile;
extern int sctrlSEUmountUmd;
extern int sctrlSESetDiscType;
extern int sctrlSESetDiscOut;
extern int sctrlKernelBootFrom;
extern int sctrlKernelMsIsEf;
extern int sctrlKernelRand;
extern int sctrlFindImportLib;
extern int sctrlFindImportByNID;
extern int sctrlHookImportByNID;
extern int sctrlHENPatchSyscall;
extern int sctrlKernelQuerySystemCall;
static const unsigned int __SystemCtrlForUser_exports[82] __attribute__((section(".rodata.sceResident"))) = {
	0x8D5BE1F0,
	0x128112C3,
	0xCB76B778,
	0xB551220C,
	0xEB74FE45,
	0xD8FF9B99,
	0xD339E2E9,
	0x2E2935EF,
	0x1090A2E1,
	0x78E46415,
	0x159AF5CC,
	0x745286D1,
	0xB47C9D77,
	0x2794CCF4,
	0x577AF198,
	0x94FE5E4B,
	0x75643FCA,
	0xABA7F1B0,
	0x7B369596,
	0xD690750F,
	0x2D10FB28,
	0xAF22D576,
	0x1DDDAD0C,
	0xAD4D5EA5,
	0x16C3B7EE,
	0x8E426F09,
	0x32414F2A,
	0x649D290E,
	0x1C90BECB,
	0x85B520C6,
	0x512E0CD8,
	0x31C6160D,
	0xFFEFA034,
	0x053FAC1D,
	0xAD9849FE,
	0xB364FBB4,
	0xFAC22931,
	0x9EFDE773,
	0x72F47790,
	0x826668E9,
	0x56CEAF00,
	(unsigned int) &sctrlKernelSetInitApitype,
	(unsigned int) &sctrlKernelSetInitFileName,
	(unsigned int) &sctrlKernelSetInitKeyConfig,
	(unsigned int) &sctrlKernelSetInitKeyConfig,
	(unsigned int) &sctrlKernelSetUserLevel,
	(unsigned int) &sctrlKernelSetDevkitVersion,
	(unsigned int) &sctrlHENIsSE,
	(unsigned int) &sctrlHENIsDevhook,
	(unsigned int) &sctrlHENGetVersion,
	(unsigned int) &sctrlHENFindDriver,
	(unsigned int) &sctrlHENFindFunction,
	(unsigned int) &sctrlHENSetMemory,
	(unsigned int) &sctrlSEGetVersion,
	(unsigned int) &sctrlKernelExitVSH,
	(unsigned int) &sctrlKernelLoadExecVSHDisc,
	(unsigned int) &sctrlKernelLoadExecVSHDiscUpdater,
	(unsigned int) &sctrlKernelLoadExecVSHMs1,
	(unsigned int) &sctrlKernelLoadExecVSHMs2,
	(unsigned int) &sctrlKernelLoadExecVSHMs3,
	(unsigned int) &sctrlKernelLoadExecVSHMs4,
	(unsigned int) &sctrlKernelLoadExecVSHWithApitype,
	(unsigned int) &sctrlKernelLoadExecVSHEf2,
	(unsigned int) &sctrlSESetConfig,
	(unsigned int) &sctrlSESetConfigEx,
	(unsigned int) &sctrlSEGetConfig,
	(unsigned int) &sctrlSEGetConfigEx,
	(unsigned int) &sctrlSERstConfig,
	(unsigned int) &sctrlSERstConfigEx,
	(unsigned int) &sctrlHENSetStartModuleHandler,
	(unsigned int) &sctrlSEMountUmdFromFile,
	(unsigned int) &sctrlSEUmountUmd,
	(unsigned int) &sctrlSESetDiscType,
	(unsigned int) &sctrlSESetDiscOut,
	(unsigned int) &sctrlKernelBootFrom,
	(unsigned int) &sctrlKernelMsIsEf,
	(unsigned int) &sctrlKernelRand,
	(unsigned int) &sctrlFindImportLib,
	(unsigned int) &sctrlFindImportByNID,
	(unsigned int) &sctrlHookImportByNID,
	(unsigned int) &sctrlHENPatchSyscall,
	(unsigned int) &sctrlKernelQuerySystemCall,
};

extern int sctrlKernelSetInitApitype;
extern int sctrlKernelSetInitFileName;
extern int sctrlKernelSetInitKeyConfig;
extern int sctrlKernelSetInitKeyConfig;
extern int sctrlKernelSetUserLevel;
extern int sctrlKernelSetDevkitVersion;
extern int sctrlHENIsSE;
extern int sctrlHENIsDevhook;
extern int sctrlHENGetVersion;
extern int sctrlHENFindDriver;
extern int sctrlHENFindFunction;
extern int sctrlSEGetVersion;
extern int sctrlKernelExitVSH;
extern int sctrlKernelLoadExecVSHDisc;
extern int sctrlKernelLoadExecVSHDiscUpdater;
extern int sctrlKernelLoadExecVSHMs1;
extern int sctrlKernelLoadExecVSHMs2;
extern int sctrlKernelLoadExecVSHMs3;
extern int sctrlKernelLoadExecVSHMs4;
extern int sctrlKernelLoadExecVSHWithApitype;
extern int sctrlKernelLoadExecVSHEf2;
extern int sctrlSESetConfig;
extern int sctrlSESetConfigEx;
extern int sctrlSEGetConfig;
extern int sctrlSEGetConfigEx;
extern int sctrlSERstConfig;
extern int sctrlSERstConfigEx;
extern int sctrlHENSetStartModuleHandler;
extern int sctrlSEMountUmdFromFile;
extern int sctrlSEUmountUmd;
extern int sctrlSESetDiscType;
extern int sctrlSEGetDiscType;
extern int sctrlSESetDiscOut;
extern int sctrlHENSetSpeed;
extern int sctrlHENSetMemory;
extern int sctrlSEGetUmdFile;
extern int sctrlSESetUmdFile;
extern int sctrlSEGetUmdFileEx;
extern int sctrlSESetUmdFileEx;
extern int sctrlSESetBootConfFileIndex;
extern int sctrlHENLoadModuleOnReboot;
extern int sctrlKernelMalloc;
extern int sctrlKernelFree;
extern int isofs_init;
extern int isofs_exit;
extern int isofs_open;
extern int isofs_read;
extern int isofs_close;
extern int isofs_lseek;
extern int isofs_getstat;
extern int isofs_fastinit;
extern int SetSpeed;
extern int sctrlSEApplyConfig;
extern int SystemCtrlForKernel_6A5F76B5;
extern int SystemCtrlForKernel_B86E36D1;
extern int SystemCtrlForKernel_07232EA5;
extern int SystemCtrlForKernel_AC0E84D1;
extern int sctrlHENRegisterKDecryptHandler;
extern int sctrlKernelBootFrom;
extern int sctrlSetStartModuleExtra;
extern int sctrlKernelSetNidResolver;
extern int sctrlKernelMsIsEf;
extern int sctrlKernelResolveNid;
extern int sctrlKernelRand;
extern int sctrlFindImportLib;
extern int sctrlFindImportByNID;
extern int sctrlHookImportByNID;
extern int sctrlHENPatchSyscall;
extern int sctrlKernelQuerySystemCall;
static const unsigned int __SystemCtrlForKernel_exports[138] __attribute__((section(".rodata.sceResident"))) = {
	0x8D5BE1F0,
	0x128112C3,
	0xCB76B778,
	0xB551220C,
	0xEB74FE45,
	0xD8FF9B99,
	0xD339E2E9,
	0x2E2935EF,
	0x1090A2E1,
	0x78E46415,
	0x159AF5CC,
	0xB47C9D77,
	0x2794CCF4,
	0x577AF198,
	0x94FE5E4B,
	0x75643FCA,
	0xABA7F1B0,
	0x7B369596,
	0xD690750F,
	0x2D10FB28,
	0xAF22D576,
	0x1DDDAD0C,
	0xAD4D5EA5,
	0x16C3B7EE,
	0x8E426F09,
	0x32414F2A,
	0x649D290E,
	0x1C90BECB,
	0x85B520C6,
	0x512E0CD8,
	0x31C6160D,
	0xABEF849B,
	0xFFEFA034,
	0xCC9ADCF8,
	0x745286D1,
	0xAC56B90B,
	0xB64186D0,
	0xBBF21F64,
	0xCF817542,
	0x5CB025F0,
	0xCE0A654E,
	0xF9584CAD,
	0xA65E8BC4,
	0x260CA420,
	0xB078D9A0,
	0xE82E932B,
	0x324FB7B1,
	0xCAE6A8E1,
	0x3BC8E648,
	0xDC974FF8,
	0x7E6F2BBA,
	0x98012538,
	0x2F157BAF,
	0x6A5F76B5,
	0xB86E36D1,
	0x07232EA5,
	0xAC0E84D1,
	0x1F3037FB,
	0x053FAC1D,
	0x221400A6,
	0x603EE1D0,
	0xAD9849FE,
	0x32677DD3,
	0xB364FBB4,
	0xFAC22931,
	0x9EFDE773,
	0x72F47790,
	0x826668E9,
	0x56CEAF00,
	(unsigned int) &sctrlKernelSetInitApitype,
	(unsigned int) &sctrlKernelSetInitFileName,
	(unsigned int) &sctrlKernelSetInitKeyConfig,
	(unsigned int) &sctrlKernelSetInitKeyConfig,
	(unsigned int) &sctrlKernelSetUserLevel,
	(unsigned int) &sctrlKernelSetDevkitVersion,
	(unsigned int) &sctrlHENIsSE,
	(unsigned int) &sctrlHENIsDevhook,
	(unsigned int) &sctrlHENGetVersion,
	(unsigned int) &sctrlHENFindDriver,
	(unsigned int) &sctrlHENFindFunction,
	(unsigned int) &sctrlSEGetVersion,
	(unsigned int) &sctrlKernelExitVSH,
	(unsigned int) &sctrlKernelLoadExecVSHDisc,
	(unsigned int) &sctrlKernelLoadExecVSHDiscUpdater,
	(unsigned int) &sctrlKernelLoadExecVSHMs1,
	(unsigned int) &sctrlKernelLoadExecVSHMs2,
	(unsigned int) &sctrlKernelLoadExecVSHMs3,
	(unsigned int) &sctrlKernelLoadExecVSHMs4,
	(unsigned int) &sctrlKernelLoadExecVSHWithApitype,
	(unsigned int) &sctrlKernelLoadExecVSHEf2,
	(unsigned int) &sctrlSESetConfig,
	(unsigned int) &sctrlSESetConfigEx,
	(unsigned int) &sctrlSEGetConfig,
	(unsigned int) &sctrlSEGetConfigEx,
	(unsigned int) &sctrlSERstConfig,
	(unsigned int) &sctrlSERstConfigEx,
	(unsigned int) &sctrlHENSetStartModuleHandler,
	(unsigned int) &sctrlSEMountUmdFromFile,
	(unsigned int) &sctrlSEUmountUmd,
	(unsigned int) &sctrlSESetDiscType,
	(unsigned int) &sctrlSEGetDiscType,
	(unsigned int) &sctrlSESetDiscOut,
	(unsigned int) &sctrlHENSetSpeed,
	(unsigned int) &sctrlHENSetMemory,
	(unsigned int) &sctrlSEGetUmdFile,
	(unsigned int) &sctrlSESetUmdFile,
	(unsigned int) &sctrlSEGetUmdFileEx,
	(unsigned int) &sctrlSESetUmdFileEx,
	(unsigned int) &sctrlSESetBootConfFileIndex,
	(unsigned int) &sctrlHENLoadModuleOnReboot,
	(unsigned int) &sctrlKernelMalloc,
	(unsigned int) &sctrlKernelFree,
	(unsigned int) &isofs_init,
	(unsigned int) &isofs_exit,
	(unsigned int) &isofs_open,
	(unsigned int) &isofs_read,
	(unsigned int) &isofs_close,
	(unsigned int) &isofs_lseek,
	(unsigned int) &isofs_getstat,
	(unsigned int) &isofs_fastinit,
	(unsigned int) &SetSpeed,
	(unsigned int) &sctrlSEApplyConfig,
	(unsigned int) &SystemCtrlForKernel_6A5F76B5,
	(unsigned int) &SystemCtrlForKernel_B86E36D1,
	(unsigned int) &SystemCtrlForKernel_07232EA5,
	(unsigned int) &SystemCtrlForKernel_AC0E84D1,
	(unsigned int) &sctrlHENRegisterKDecryptHandler,
	(unsigned int) &sctrlKernelBootFrom,
	(unsigned int) &sctrlSetStartModuleExtra,
	(unsigned int) &sctrlKernelSetNidResolver,
	(unsigned int) &sctrlKernelMsIsEf,
	(unsigned int) &sctrlKernelResolveNid,
	(unsigned int) &sctrlKernelRand,
	(unsigned int) &sctrlFindImportLib,
	(unsigned int) &sctrlFindImportByNID,
	(unsigned int) &sctrlHookImportByNID,
	(unsigned int) &sctrlHENPatchSyscall,
	(unsigned int) &sctrlKernelQuerySystemCall,
};

const struct _PspLibraryEntry __library_exports[5] __attribute__((section(".lib.ent"), used)) = {
	{ NULL, 0x0000, 0x8000, 4, 2, 1, (unsigned int *) &__syslib_exports },
	{ "KUBridge", 0x0000, 0x4001, 4, 0, 10, (unsigned int *) &__KUBridge_exports },
	{ "MECtrl", 0x0000, 0x4001, 4, 0, 6, (unsigned int *) &__MECtrl_exports },
	{ "SystemCtrlForUser", 0x0000, 0x4001, 4, 0, 41, (unsigned int *) &__SystemCtrlForUser_exports },
	{ "SystemCtrlForKernel", 0x0000, 0x0001, 4, 0, 69, (unsigned int *) &__SystemCtrlForKernel_exports },
};

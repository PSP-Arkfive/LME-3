#include <pspsdk.h>
#include <pspkernel.h>

int sctrlSEGetVersion()
{
	return 0x00010030;
}

int	sctrlHENIsSE()
{
	return 1;
}

int	sctrlHENIsDevhook()
{
	return 0;
}

int sctrlHENGetVersion()
{
	return 0x00001000;
}

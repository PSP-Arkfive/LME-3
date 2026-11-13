# LME flash installer

This PSP-only installer uses LibPspExploit for kernel access. It installs and
verifies the LME files in flash0 and automatically reboots into LME after a
successful installation. An LME-compatible loader is not required for the initial
reboot. It is not intended for Vita, Adrenaline, or other emulators.

Flashing can brick a PSP. Use a known-good NAND backup and recovery method,
connect AC power, charge the battery to at least 50%, and do not interrupt the
installer. If a write fails, flash0 may be partially updated; the installer
reports the error rather than claiming success. Existing files are overwritten
and are not backed up by the installer.

Place `EBOOT.PBP`, `usbdevice.prx`, and the package matching the installed firmware together in
`PSP/GAME/LMEINSTALLER/` on the storage device. The package names are
`FLASH620.LME`, `FLASH639.LME`, `FLASH660.LME`, and `FLASH661.LME`.
6.60 and 6.61 use different firmware-specific builds; they are not
interchangeable. Only packages actually built and distributed are available.
The installer rejects unsupported firmware/model combinations and incomplete
or malformed packages before opening flash0 for writing. The archive format
does not authenticate its contents: only use packages from a trusted source.

The installer copies the compressed USB module to `flash0:/kd/usbdev.prx`.
The build downloads the universal module from psp-dynamic-libraries and
compresses it using psp-cfw-sdk.

From the project root, `make dist TARGET_FW=660` builds the 6.60 package and
installer under `dist/PSP/GAME/LMEINSTALLER/`. The build also accepts 620, 639,
and 661. Clean the project before switching `TARGET_FW`, because the existing
component makefiles reuse object files across firmware builds. Install the
PSP toolchain and psp-cfw-sdk (including LibPspExploit) first.

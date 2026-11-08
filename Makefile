BUILD = 2.3

ifeq ($(TARGET_FW), 639)
BUILD = 10.3
endif

ifndef $(TARGET_FW)
TARGET_FW = 150
endif

all: psp-tools common cfw
lite: common lcfw
double: common cfw lcfw

psp-tools:
	make -C PSP_TOOLS

cfw:
	make -C vshctrl			TARGET_FW=$(TARGET_FW)

lcfw:
#	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=2
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=4
ifeq ($(TARGET_FW), 620)
#	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=2 PERMANENT=1
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=4 PERMANENT=1
endif
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=4
ifeq ($(TARGET_FW), 620)
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2 PERMANENT=1
	make -C systemctrl 		TARGET_FW=$(TARGET_FW) PSP_MODEL=4 PERMANENT=1
endif
	make -C vshctrl 		TARGET_FW=$(TARGET_FW) HEN=1
	make -C rebootex_lite	TARGET_FW=$(TARGET_FW) PSP_MODEL=0
	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=1
#	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=2
	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=4
ifeq ($(TARGET_FW), 620)
	make -C rebootex_lite	TARGET_FW=$(TARGET_FW) PSP_MODEL=0 PERMANENT=1
	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=1 PERMANENT=1
#	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=2 PERMANENT=1
	make -C rebootex_lite 	TARGET_FW=$(TARGET_FW) PSP_MODEL=4 PERMANENT=1
endif


common:
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=0
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=1
ifeq ($(TARGET_FW), 620)
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=0 PERMANENT=1
	make -C rebootex		TARGET_FW=$(TARGET_FW) PSP_MODEL=1 PERMANENT=1
endif
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=0
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=1
ifeq ($(TARGET_FW), 620)
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=0 PERMANENT=1
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=1 PERMANENT=1
endif
	make -C horoscope		TARGET_FW=$(TARGET_FW)
	make -C idcanager		TARGET_FW=$(TARGET_FW)
	make -C galaxy			TARGET_FW=$(TARGET_FW)
	make -C march33			TARGET_FW=$(TARGET_FW)
	make -C inferno			TARGET_FW=$(TARGET_FW)
	make -C recovery/kernel	TARGET_FW=$(TARGET_FW)
	make -C recovery		TARGET_FW=$(TARGET_FW)
	make -C vshmenu_new		TARGET_FW=$(TARGET_FW)
#	make -C usbdevice		TARGET_FW=$(TARGET_FW)
	make -C dax9660			TARGET_FW=$(TARGET_FW)
	make -C pspbtjnf		TARGET_FW=$(TARGET_FW)

clean:
	make clean -C dax9660
	make clean -C documents
	make clean -C galaxy
	make clean -C horoscope
	make clean -C idcanager
	make clean -C march33
	make clean -C inferno
	make clean -C pspbtjnf
	make clean -C rebootex PSP_MODEL=0
	make clean -C rebootex PSP_MODEL=1
#	make clean -C rebootex PSP_MODEL=2
	make clean -C rebootex PSP_MODEL=4
#ifeq ($(TARGET_FW), 620)	
	make clean -C rebootex PSP_MODEL=0 PERMANENT=1
	make clean -C rebootex PSP_MODEL=1 PERMANENT=1
#	make clean -C rebootex PSP_MODEL=2 PERMANENT=1
	make clean -C rebootex PSP_MODEL=4 PERMANENT=1
#endif
	make clean -C rebootex_lite PSP_MODEL=0
	make clean -C rebootex_lite PSP_MODEL=1
#	make clean -C rebootex_lite PSP_MODEL=2
	make clean -C rebootex_lite PSP_MODEL=4
#ifeq ($(TARGET_FW), 620)
	make clean -C rebootex_lite PSP_MODEL=0 PERMANENT=1
	make clean -C rebootex_lite PSP_MODEL=1 PERMANENT=1
#	make clean -C rebootex_lite PSP_MODEL=2 PERMANENT=1
	make clean -C rebootex_lite PSP_MODEL=4 PERMANENT=1
#endif
	make clean -C recovery
	make clean -C recovery/kernel
	make clean -C systemctrl PSP_MODEL=0
	make clean -C systemctrl PSP_MODEL=1
	make clean -C systemctrl PSP_MODEL=2
	make clean -C systemctrl PSP_MODEL=4
#ifeq ($(TARGET_FW), 620)
	make clean -C systemctrl PSP_MODEL=0 PERMANENT=1
	make clean -C systemctrl PSP_MODEL=1 PERMANENT=1
	make clean -C systemctrl PSP_MODEL=2 PERMANENT=1
	make clean -C systemctrl PSP_MODEL=4 PERMANENT=1
#endif
#	make clean -C usbdevice
	make clean -C vshctrl
	make clean -C vshctrl HEN=1	
	make clean -C vshmenu_new
	rm -rf dist

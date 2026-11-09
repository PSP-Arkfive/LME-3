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

dist: all double
	mkdir -p dist/flash0/kd
	mkdir -p dist/flash0/vsh/module
	cp systemctrl/systemctrl*.prx dist/flash0/kd/
	cp vshctrl/vshctrl*.prx dist/flash0/kd/
	cp horoscope/horoscope.prx dist/flash0/kd/
	cp idcanager/idmanager.prx dist/flash0/kd/
	cp galaxy/pulsar.prx dist/flash0/kd/
	cp march33/isotope.prx dist/flash0/kd/
	cp inferno/inferno.prx dist/flash0/kd/
	cp dax9660/dax9660.prx dist/flash0/kd/
	cp recovery/recovery.prx dist/flash0/vsh/module/
	cp vshmenu/satellite.prx dist/flash0/vsh/module/
	cp pspbtjnf/$(TARGET_FW)/bin/*.bin dist/flash0/kd/


psp-tools:
	make -C PSP_TOOLS

cfw:
	make -C vshctrl			TARGET_FW=$(TARGET_FW)

lcfw:
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=4
ifeq ($(TARGET_FW), 620)
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2 PERMANENT=1
	make -C systemctrl 		TARGET_FW=$(TARGET_FW) PSP_MODEL=4 PERMANENT=1
endif
	make -C vshctrl 		TARGET_FW=$(TARGET_FW) HEN=1


common:
	make -C rebootex
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
	make -C vshmenu		    TARGET_FW=$(TARGET_FW)
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
	make clean -C rebootex
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
	make clean -C vshctrl
	make clean -C vshctrl HEN=1	
	make clean -C vshmenu
	rm -rf dist

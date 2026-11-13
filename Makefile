PY = $(shell which python3)
PSPDEV = $(shell psp-config --pspdev-path)
BUILDTOOLS = $(PSPDEV)/share/psp-cfw-sdk/build-tools
TARGET_FW ?= 660
LIBS_DIR = .usbdevice-build
LIBS_ARCHIVE = $(LIBS_DIR)/LIBS.zip
LIBS_URL = https://github.com/pspdev/psp-dynamic-libraries/releases/download/latest/LIBS.zip

all: psp-tools common cfw
lite: common lcfw
double: common cfw lcfw

dist: psp-tools libs_latest double installer
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
	mv dist/flash0/kd/pspbtjnf_01g.bin dist/flash0/kd/pspbtjnf.bin
	$(PY) installer/pack.py $(TARGET_FW) flash0.txt dist/FLASH$(TARGET_FW).LME
	mkdir -p dist/PSP/GAME/LMEINSTALLER
	rm -f dist/PSP/GAME/LMEINSTALLER/usbdevice.prx
	cd $(LIBS_DIR) && $(PY) $(BUILDTOOLS)/gz/pspgz.py $(abspath dist/PSP/GAME/LMEINSTALLER/usbdevice.prx) $(BUILDTOOLS)/gz/SystemControl.hdr usbdevice.prx pspUsbDev_Driver 0x1006
	test -s dist/PSP/GAME/LMEINSTALLER/usbdevice.prx
	cp installer/EBOOT.PBP dist/FLASH$(TARGET_FW).LME dist/PSP/GAME/LMEINSTALLER/

installer:
	$(MAKE) -C installer

psp-tools:
	make -C PSP_TOOLS

cfw:
	$(MAKE) -C vshctrl clean
	make -C vshctrl			TARGET_FW=$(TARGET_FW)

lcfw:
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=4
ifeq ($(TARGET_FW), 620)
	make -C systemctrl		TARGET_FW=$(TARGET_FW) PSP_MODEL=2 PERMANENT=1
	make -C systemctrl 		TARGET_FW=$(TARGET_FW) PSP_MODEL=4 PERMANENT=1
endif
	$(MAKE) -C vshctrl clean HEN=1
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

libs_latest:
	mkdir -p $(LIBS_DIR)
	curl --fail --location --silent --show-error "$(LIBS_URL)" -o "$(LIBS_ARCHIVE)"
	unzip -o "$(LIBS_ARCHIVE)" usbdevice.prx -d "$(LIBS_DIR)"

clean:
	$(MAKE) clean -C installer
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
	rm -rf $(LIBS_DIR)

.PHONY: all lite double dist installer psp-tools cfw lcfw common libs_latest clean
.NOTPARALLEL: double dist

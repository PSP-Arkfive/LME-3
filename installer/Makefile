TARGET = lmeinstaller
OBJS = main.o kernel.o package.o

CFLAGS = -O2 -G0 -Wall -Wextra -std=c99
BUILD_PRX = 1
ENCRYPT = 1
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = LME Installer
LIBS = -lpspexploit -lpsppower
INCDIR = ../rebootex

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

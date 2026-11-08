PSP-BTCNF        = psp-btcnf
PSP-PACKER       = psp-packer

all:
	make -C $(PSP-BTCNF)
	make -C $(PSP-PACKER)

install:
	make -C $(PSP-BTCNF) install
	make -C $(PSP-PACKER) install

uninstall:
	make -C $(PSP-BTCNF) uninstall
	make -C $(PSP-PACKER) uninstall

clean:
	make -C $(PSP-BTCNF) clean
	make -C $(PSP-PACKER) clean

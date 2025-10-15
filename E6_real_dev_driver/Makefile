obj-m := E6_real_dev_driver.o

KDIR:=~/BBB/linux

ARCH:=arm

CROSS_COMPILE:= arm-linux-gnueabihf-

all:
	make -C $(KDIR) M=$(PWD) CROSS_COMPILE=$(CROSS_COMPILE) ARCH=$(ARCH) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

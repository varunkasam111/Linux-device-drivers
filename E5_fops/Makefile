obj-m := E5_fops.o

KDIR := ~/BBB/linux

ARCH := arm

CROSS_COMPILE := arm-linux-gnueabihf-

all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

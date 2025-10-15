obj-m += E4_alloc_dev.o

KDIR := ~/BBB/linux

CROSS_COMPILE := arm-linux-gnueabihf-

ARCH := arm

all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

obj-m += E3_maj_min.o

#KDIR := ~/BBB/bb-kernel-6.16.5/KERNEL
#KDIR := ~/BBB/bbb-kernel-headers
KDIR := /home/pe-rnd3/BBB/tmp/lib/modules/6.1.83/build
#KDIR := /home/pe-rnd3/BBB/linux

ARCH := arm
CROSS_COMPILE := arm-linux-gnueabihf-
#CROSS_COMPILE := arm-linux-gnueabi-


all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) clean



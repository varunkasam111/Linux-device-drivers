obj-m += hello.o

KDIR := ~/BBB/bb-kernel-6.16.5/KERNEL
ARCH := arm
CROSS_COMPILE := arm-linux-gnueabihf-

all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) clean


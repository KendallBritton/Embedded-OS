# Cross compilation Makefile for ARM
# Change KERN_SRC appropriately
KERN_SRC=/home/kbritto/ECGR-6181/Lab3/linux-6.0.2
obj-m = mem.o
 
all: 
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) modules
	arm-linux-gnueabi-gcc -Wall --static -O2 -mcpu=arm926ej-s mem_test.c -o mem_test

clean:
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) clean





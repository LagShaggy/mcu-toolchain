#!/bin/bash

git clone https://github.com/u-boot/u-boot
cd u-boot

printf "You have entered the automatic U-Boot building procedure.\n"
printf "You can build one of the following options:\n"
printf "qemu, stm32f429-disco, test\n"
read var

case $var in
        "qemu")
                make mrproper
                make ARCH=arm CROSS_COMPILE=arm-none-eabi- qemu_arm_defconfig
                make ARCH=arm CROSS_COMPILE=arm-none-eabi-
                ;;
        "stm32f429-disco")
                make mrproper
                make ARCH=arm CROSS_COMPILE=arm-none-eabi- stm32f429-discovery_defconfig
                make ARCH=arm CROSS_COMPILE=arm-none-eabi-
                ;;
                
        "test")
                echo "Testing"
                ;;
        *)
                echo "Not a valid argument"
                echo
                ;;
esac


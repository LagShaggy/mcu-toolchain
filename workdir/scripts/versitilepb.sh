make ARCH=arm CROSS_COMPILE=arm-none-eabi- mrproper
make ARCH=arm CROSS_COMPILE=arm-none-eabi- versatile_defconfig
make ARCH=arm CROSS_COMPILE=arm-none-eabi- zImage
make ARCH=arm CROSS_COMPILE=arm-none-eabi- modules
make ARCH=arm CROSS_COMPILE=arm-none-eabi- dtbs
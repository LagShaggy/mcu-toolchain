make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mrproper
make -j4 ARCH=arm versatile_defconfig
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- dtbs

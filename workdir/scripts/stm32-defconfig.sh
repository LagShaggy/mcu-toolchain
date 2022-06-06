make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mrproper
make -j4 ARCH=arm stm32_defconfig
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- xipImage
make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- dtbs

echo "Copying files to host OS -> C:\linux\"

cp -v vmlinux /workdir/linux/stm32-defconfig/
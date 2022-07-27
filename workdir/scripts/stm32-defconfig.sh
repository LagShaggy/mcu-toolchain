make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mrproper
make ARCH=arm stm32_defconfig
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- xipImage
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- dtbs

echo "Copying files to host OS -> C:\linux\"

cp -v vmlinux /workdir/linux/stm32-defconfig/
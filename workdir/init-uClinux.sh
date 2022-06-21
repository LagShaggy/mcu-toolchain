#!/bin/bash

echo "Setting up toolchains"
cd /workdir
wget https://sourcery.mentor.com/GNUToolchain/package6503/public/arm-uclinuxeabi/arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2
tar -xf arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2
rm -d arm-2010q1-189-arm-uclinuxeabi-i686-pc-linux-gnu.tar.bz2
export PATH=/workdir/arm-2010q1/bin:$PATH

#what exactly did I do here?
dpkg --add-architecture i386
apt-get update && apt-get upgrade -y
apt-get install	libc6:i386

#download emcraft uClinux
git clone https://github.com/EmcraftSystems/linux-emcraft.git
git clone https://github.com/EmcraftSystems/u-boot.git

#fixing filname so compiles work
cp /workdir/linux-emcraft/initramfs-list-min.stub /workdir/linux-emcraft/initramfs-list-min
cp /workdir/linux-emcraft/arch/arm/kernel/vmlinux.lds.S.good /workdir/linux-emcraft/arch/arm/kernel/vmlinux.lds.S

echo "compiling uClinux"
make -j4 ARCH=arm CROSS_COMPILE=arm-uclinuxeabi- zImage
mkdir /workdir/output/uClinux/
cp ./vmlinux /workdir/output/
#!/bin/bash
apt-get install -y \
gcc \
git \
binutils-arm-none-eabi \
make \
gcc-arm-none-eabi \
libncurses-dev \
libncurses5-dev \
flex \
bison \
openssl \
libssl-dev \
dkms \
libelf-dev \
libudev-dev \
libpci-dev \
libiberty-dev \
autoconf \
gcc-9-arm-linux-gnueabi \
gcc-9-arm-linux-gnueabihf \
gcc-arm-linux-gnueabihf \
gcc-arm-linux-gnueabi \
gcc-multilib \
lzop \
bc \
nano \
curl \
wget 

printf 'y\n8\n7\n' | apt-get install -y qemu-system-arm
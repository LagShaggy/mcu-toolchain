#!/bin/bash
printf 'y\n8\n7\n' | apt-get install -y qemu-system-arm
apt-get install -y gcc \
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
perl \
libelf-dev \
libudev-dev \
libpci-dev \
libiberty-dev \
autoconf \
gcc-arm-linux-gnueabihf \
gcc-arm-linux-gnueabi \
lzop \
bc \
nano \
curl \
wget
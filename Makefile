all:
    arm-none-eabi-as --warn --fatal-warnings -mcpu=cortex-m3 flash.s -o flash.o
    arm-none-eabi-gcc -Wall -O2 -ffreestanding -mcpu=cortex-m3 -mthumb -c notmain.c -o notmain.o
    arm-none-eabi-ld -nostdlib -nostartfiles -T flash.ld flash.o notmain.o -o notmain.elf
    arm-none-eabi-objdump -D notmain.elf > notmain.list
    arm-none-eabi-objcopy -O binary notmain.elf notmain.bin
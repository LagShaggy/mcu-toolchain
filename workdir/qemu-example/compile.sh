printf 'arm-none-eabi-as --warn --fatal-warnings -mcpu=cortex-m4 flash.s -o flash.o\n'
arm-none-eabi-as --warn --fatal-warnings -mcpu=cortex-m4 flash.s -o flash.o

printf 'arm-none-eabi-gcc -Wall -O2 -ffreestanding -mcpu=cortex-m4 -mthumb -c notmain.c -o notmain.o\n'
arm-none-eabi-gcc -Wall -O2 -ffreestanding -mcpu=cortex-m4 -mthumb -c notmain.c -o notmain.o

printf 'arm-none-eabi-ld -nostdlib -nostartfiles -T flash.ld flash.o notmain.o -o notmain.elf\n'
arm-none-eabi-ld -nostdlib -nostartfiles -T flash.ld flash.o notmain.o -o notmain.elf

printf 'arm-none-eabi-objdump -D notmain.elf > notmain.list\n'
arm-none-eabi-objdump -D notmain.elf > notmain.list

printf 'arm-none-eabi-objcopy -O binary notmain.elf notmain.bin\n'
arm-none-eabi-objcopy -O binary notmain.elf notmain.bin

printf 'Running the compiled files with qemu-system-arm:\n'
qemu-system-arm -M lm3s811evb -cpu cortex-m4 -m 8K -nographic -kernel notmain.bin
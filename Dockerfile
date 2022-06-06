FROM ubuntu:20.04

RUN mkdir /workdir
WORKDIR /workdir
ADD workdir/ .

RUN apt-get update && apt-get upgrade -y
## input all the commands for all installation prompts
RUN printf 'y\n8\n7\n' | apt-get install -y qemu-system-arm
## make script executable
RUN chmod u+x ./installscript.sh
## convert DOS EOL to linux
RUN sed -i -e 's/\r$//' ./installscript.sh
RUN ./installscript.sh 

## untar linux
RUN tar -xf linux-5.17.8.tar.xz
RUN mv scripts/ linux-5.17.8

#RUN qemu-system-arm -machine versatileab -cpu cortex-m4 -nographic -monitor null -semihosting -append 'some program arguments' -kernel program.axf

ENTRYPOINT ["/bin/bash"]
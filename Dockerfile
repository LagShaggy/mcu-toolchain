FROM ubuntu:20.04

RUN mkdir -p /workdir/output
WORKDIR /workdir
ADD workdir/ .

RUN apt-get update && apt-get upgrade -y

## make script executable
RUN chmod u+x ./installscript.sh
## convert DOS EOL to linux
RUN sed -i -e 's/\r$//' ./installscript.sh
RUN ./installscript.sh 

## untar linux
RUN tar -xf linux-5.18.5.tar.xz
RUN mv scripts/* linux-5.18.5/
RUN rm -d scripts

#RUN qemu-system-arm -machine versatileab -cpu cortex-m4 -nographic -monitor null -semihosting -append 'some program arguments' -kernel program.axf

ENTRYPOINT ["/bin/bash"]
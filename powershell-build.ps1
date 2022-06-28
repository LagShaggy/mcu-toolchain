docker build -t mcu-toolchain:v2 .
docker run -it -v "${PWD}/output/:/workdir/output/" mcu-toolchain:v2
Embedding MicroPython in an ESP IDF Project
===========================================

This is a quick example project to demo the way I managed to embed Micropython into an existing ESP IDF project.

The program doesn't do much but does incorporate Micropython and it is the build scripts that are the main event.

The approach is to run the MicroPython build system from within the ESP IDF but then pull all of the source code (including the dynamically generated header files) into the ESP IDF project directly. So the only reason for running the MicroPython build is to generate those dynamic files.

First you will need to ensure the ESP IDF is installed. I have found that it works fine with the current head of the master branch (which is what the linux and mac instructions end up installing) but you may find that some subsequent commits to the ESP IDF break things and in that case you will need to follow instructions to set a specific version of the IDF - e.g. to select 4.1

```shell
cd ~/esp/esp-idf
git checkout v4.1
git submodule update --init
```

Note that after doing this you will probably need to reinstall the ESP IDF toolchain:
```shell
./install.sh
```

Then clone the repo to a folder of your choosing (with --recursive to ensure the MicroPython submodule is downloaded)

```shell
git clone --recursive https://github.com/robdobsn/MicroPythonESP32Embedding
```

Then follow the instructions in the MicroPython README (in the external/micropython folder), incuding building the mpy-cross cross compiler.

```shell
cd ./external/micropython/mpy-cross
make
cd ../../..
```

Finally setup the environment for IDF building and build:

```shell
. $HOME/esp/esp-idf/export.sh
idf.py build
```

Embedding MicroPython in an ESP IDF Project
===========================================

This is a quick example project to demo the way I managed to embed Micropython into an existing ESP IDF project.

The program doesn't do much but does incorporate Micropython and it is the build scripts that are the main event.

The approach is to run the MicroPython build system from within the ESP IDF but then pull all of the source code (including the dynamically generated header files) into the ESP IDF project directly. So the only reason for running the MicroPython build is to generate those dynamic files.

To get it going you will need to ensure the ESP IDF is installed first, then:

git clone --recursive MicroPythonESP32Embedding
cd MicroPythonESP32Embedding/external/micropython/mpy-cross
make
cd ../../..
. $HOME/esp/esp-idf/export.sh
idf.py build

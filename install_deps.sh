#!/bin/bash

PROJECT_ROOT=$(pwd)

cd tools/source/msgenc
make
cd $PROJECT_ROOT
mv tools/source/msgenc/msgenc tools/msgenc

rm -rf tools/source/ndstool
cd tools/source
git clone https://github.com/devkitPro/ndstool.git
cd ndstool
git checkout fa6b6d01881363eb2cd6e31d794f51440791f336
find . -name '*.sh' -execdir
./autogen.sh
./configure && make
cd $PROJECT_ROOT
mv tools/source/ndstool/ndstool tools/ndstool
rm -rf tools/source/ndstool

rm -rf tools/source/armips
cd tools/source
git clone --recursive https://github.com/Kingcom/armips.git
cd armips
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cd $PROJECT_ROOT
mv tools/source/armips/build/armips tools/armips
rm -rf tools/source/armips
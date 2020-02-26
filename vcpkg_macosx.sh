#!/bin/bash
set -e

mkdir -p build
cd build
git clone https://github.com/Microsoft/vcpkg.git vcpkg.macosx
cd vcpkg.macosx
git checkout 2020.01
./bootstrap-vcpkg.sh

./vcpkg install \
	sdl2:x64-osx \
	sdl2-mixer:x64-osx
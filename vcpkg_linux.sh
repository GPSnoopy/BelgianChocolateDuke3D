#!/bin/bash
set -e

mkdir -p build
cd build
git clone https://github.com/Microsoft/vcpkg.git vcpkg.linux
cd vcpkg.linux
git checkout 2020.01
./bootstrap-vcpkg.sh

./vcpkg install \
	enet:x64-linux \
	sdl2:x64-linux \
	sdl2-mixer:x64-linux

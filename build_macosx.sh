#!/bin/bash
set -e

mkdir --parents build/linux
cd build/linux
cmake -D VCPKG_TARGET_TRIPLET=x64-windows-static -D CMAKE_TOOLCHAIN_FILE=../vcpkg.windows.x64/scripts/buildsystems/vcpkg.cmake -D CMAKE_BUILD_TYPE=Release ../..
make -j

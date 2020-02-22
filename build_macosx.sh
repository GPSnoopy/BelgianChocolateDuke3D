#!/bin/bash
set -e

mkdir -p build/linux
cd build/linux
cmake -D VCPKG_TARGET_TRIPLET=x64-osx -D CMAKE_TOOLCHAIN_FILE=../vcpkg.macosx/scripts/buildsystems/vcpkg.cmake -D CMAKE_BUILD_TYPE=Release ../..
make -j

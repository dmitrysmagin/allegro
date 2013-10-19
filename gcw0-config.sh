#!/bin/sh

rm -f allegro-config Makefile cmake_install.cmake CMakeCache.txt
cmake \
      -DWANT_LINUX_CONSOLE=ON \
      -DWANT_LINUX_FBCON=ON \
      -DWANT_LINUX_SVGALIB=OFF \
      -DWANT_LINUX_VGA=OFF \
      -DWANT_X11=OFF \
      -DWANT_ALSA=ON \
      -DWANT_JACK=OFF \
      -DWANT_OSS=OFF \
      -DWANT_SGIAUDIO=OFF \
      -DWANT_DOCS=OFF \
      -DWANT_EMBED=OFF \
      -DWANT_FRAMEWORKS=OFF \
      -DWANT_JPGALLEG=ON \
      -DWANT_LOADPNG=ON \
      -DWANT_LOGG=ON \
      -DWANT_ALLEGROGL=OFF \
      -DWANT_EXAMPLES=OFF -DWANT_TESTS=OFF -DWANT_TOOLS=ON \
      -DWANT_MODULES=OFF -DSHARED=ON \
      -DCMAKE_INSTALL_PREFIX=/opt/gcw0-toolchain/usr/mipsel-gcw0-linux-uclibc/sysroot/usr \
      -DCMAKE_BUILD_TYPE="Release" \
      -DCMAKE_C_FLAGS="-mips32 -O2" -DCMAKE_CXX_FLAGS="-mips32 -O2" \
      -DCMAKE_C_FLAGS_DEBUG="-mips32 -O1 -g -DDEBUGMODE=1" \
      -DCMAKE_CXX_FLAGS_DEBUG="-mips32 -O1 -g -DDEBUGMODE=1" \
      -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-gcw0.cmake .


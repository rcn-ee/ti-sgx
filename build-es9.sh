#!/bin/bash

ARCH=$(uname -m)

x86_dir="/opt/github/ti-linux-kernel-dev"
x86_compiler="gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-"

if [ "x${ARCH}" = "xarmv7l" ] ; then
	make_options="GRAPHICS_INSTALL_DIR=./ KERNEL_INSTALL_DIR=/build/buildd/linux-src CSTOOL_DIR=/usr/ CSTOOL_PREFIX= "
else
	make_options="GRAPHICS_INSTALL_DIR=./ KERNEL_INSTALL_DIR=${x86_dir}/KERNEL CSTOOL_DIR=${x86_dir}/dl/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux CSTOOL_PREFIX=arm-linux-gnueabihf-"
fi

mkdir -p ./gfx_rel_es9.x || true
make ARCH=arm ${make_options} clean
make ARCH=arm ${make_options} BUILD=release OMAPES=9.x FBDEV=yes all
#

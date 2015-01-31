#!/bin/bash

ARCH=$(uname -m)

if [ "x${ARCH}" = "xarmv7l" ] ; then
	uname_r="VERSION"
	distro="DISTRO"
	dpkg_arch="armhf"
else
	uname_r="3.14.19-ti-r24"
	distro="wheezy"
	dpkg_arch="amd64"
fi

package="ti-sgx"
base_dir="./"

es="es9"

if [ -f ${base_dir}src/gfx_rel_${es}.x/pvrsrvkm.ko ] ; then

	#modules
	cp -v ${base_dir}src/gfx_rel_${es}.x/pvrsrvkm.ko ${base_dir}
	cp -v ${base_dir}src/gfx_rel_${es}.x/omaplfb.ko ${base_dir}
	cp -v ${base_dir}src/gfx_rel_${es}.x/bufferclass_ti.ko ${base_dir}

	#readme
	cp -v ${base_dir}src/GFX_Linux_KM/README ${base_dir}

	echo "Section: misc" > ${base_dir}control
	echo "Priority: optional" >> ${base_dir}control
	echo "Homepage: https://github.com/rcn-ee/${package}" >> ${base_dir}control
	echo "Standards-Version: 3.9.6" >> ${base_dir}control
	echo "" >> ${base_dir}control
	echo "Package: ${package}-${es}-modules-${uname_r}" >> ${base_dir}control
	echo "Version: 1${distro}" >> ${base_dir}control
	echo "Pre-Depends: linux-image-${uname_r}" >> ${base_dir}control
	echo "Depends: linux-image-${uname_r}" >> ${base_dir}control
	echo "Maintainer: Robert Nelson <robertcnelson@gmail.com>" >> ${base_dir}control
	echo "Architecture: ${dpkg_arch}" >> ${base_dir}control
	echo "Readme: README" >> ${base_dir}control
	echo "Files: pvrsrvkm.ko /lib/modules/${uname_r}/extra/${es}.x/" >> ${base_dir}control
	echo " omaplfb.ko /lib/modules/${uname_r}/extra/${es}.x/" >> ${base_dir}control
	echo " bufferclass_ti.ko /lib/modules/${uname_r}/extra/${es}.x/" >> ${base_dir}control
	echo "Description: ${package} modules" >> ${base_dir}control
	echo " Kernel modules for ${package} devices" >> ${base_dir}control
	echo "" >> ${base_dir}control

	equivs-build control

	rm -rf pvrsrvkm.ko || true
	rm -rf omaplfb.ko || true
	rm -rf bufferclass_ti.ko || true
	rm -rf README || true
	rm -rf control || true
fi

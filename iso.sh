#!/bin/sh

set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/kuriOS.kernel isodir/boot/kuriOS.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "KuriOS" {
	multiboot /boot/kuriOS.kernel
}
EOF

grub-mkrescue -o kuriOS.iso isodir

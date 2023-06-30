#!/bin/sh

set -e
. ./iso.sh

qemu-system-$(-./target-triplet-t-arch.sh $HOST) -cdrom KuriOS.iso

CC=/opt/cross/bin/x86_64-elf-gcc
CXX=/opt/cross/bin/x86_64-elf-g++


ROOTDIR := shell if [ "$$PWD" != ""] ; then echo $$PWD ; else pwd ; fi
INCLUDE = $(ROOTDIR)/include


DIRS = 	kernel \
	libc


OBJS = \
	kernel/*.o






all:
	@for n in $(DIRS) ; do cd $$n ; $(MAKE) || exit ; done
	$(LD) -N -T link.ld -o kuriOS


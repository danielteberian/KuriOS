DEFAULT_HOST!=../default-host.sh
HOST?=x86_64-elf
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config


KERNEL_OBJS= $(KERNEL_ARCH_OBJS) kernel/kernel.o


OBJS = $(ARCHDIR)/crti.o $(ARCHDIR)/crtbegin.o $(KERNEL_ARCH_OBJS) $(ARCHDIR)/crtend.o $(ARCHDIR)/crtn.o


LINK_LIST = $(LDFLAGS) $(ARCHDIR)/crti.o $(ARCHDIR)/crtbegin.o $(KERNEL_OBJS) $(LIBS) $(ARCHDIR)/crtend.o $(ARCHDIR/crtn.o


.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S

all: KuriOS.kernel

KuriOS.kernel: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot KuriOS.kernel

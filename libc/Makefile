

ARFLAGS = -crs
CFLAGS ?= -O2 -g
CFLAGS += --sysroot=$(SYSROOT) -std=gnu11 -ffreestanding -fno-common
CFLAGS += -fstack-protector-strong
CFLAGS += -Wall - Wextra
CPPFLAGS += -I include -D_ALL_SOURCE

LIBC_FLAGS += -D__kuriOS_libc
LIBK_FLAGS += -D__kuriOS_libk


COMMON_OBJ = \
	stdio/printf \
	stdio/putchar \
	stdio/puts \
	stdlib/abort \
	string/memchr \
	string/memcmp \
	string/memcpy \
	string/memmove \
	string/memset \
	string/strlen

# Set constants for Multiboot header:
.set ALIGN,				1 << 0			# Aligns loaded modules on page boundaries
.set MEMINFO,				1 << 1			# Memory mapping
.set FLAGS,				ALIGN | MEMINFO		# Multiboot "flag" field
.set MAGIC,				0x1BADB002		# Magic number
.set CHECKSUM,				-(MAGIC + FLAGS)	# Checksum, verifies is Multiboot


# Declare header, according to Multiboot specifications:
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM


# Reserve stack for initial thread:
.section .bss
.align 16

stack_bottom:
.skip 16384							# 16 KB

stack_top:


# Kernel entry-point:
.section .text
.global _start
.type _start, @function

_start:
	movl $stack_top, %esp
	call _init						# Call global instructors
	call kernel_main					# Transfer control to kernel
	cli							# If kernel_main returns unexpectedly, hang

1:	hlt
	jmp 1b
.size _start, . - _start

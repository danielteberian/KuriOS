.section .init
.global _init
.type _init, @function

_init:
	push %rbp
	movl %esp, %ebp

.section .fini
.global _fini
.type _fini, @function

_fini:
	push %rbp
	movl %esp, %ebp

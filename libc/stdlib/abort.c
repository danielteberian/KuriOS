#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void)
{
	printf("KERNEL: PANIC: ABORT()\n");
	asm volatile("hlt");

	printf("ABORT()\n")

	while (1)
	{

	}
	__builtin_unreachable();
}

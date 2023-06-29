#include <stdio.h>
#include "tty.h"

void kernel_main(void)
{
	term_init();
	printf("Howdy, kernel!\n");
}

ENTRY(_start)
SECTIONS
{
	. = KERNEL_VMA;

	.text : AT(ADDR(.text) - KERNEL_VMA)
	{
		_code = .;
		*(.text)
		*(.rodata*)
		. = ALIGN(4096);
	}

	.data : AT(ADDR(.data) - KERNEL_VMA)
	{
		_data = .;
		*(.data)
		. = ALIGN(4096);
	}

	.eh_frame : AT(ADDR(.eh_frame) - KERNEL_VMA)
	{
		_ehframe = .;
		*(.eh_frame)
		. = ALIGN(4096);
	}

	.bss : AT(ADDR(.bss) - KERNEL_VMA)
	{
		_bss = .;
		*(.bss)
	/* ADD STUFF HERE */
		*(COMMON)
		. = ALIGN(4096);
	}

	_end = .;

	/DISCARD/ :
	{
		*(.comment)
	}
}

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "tty.h"
#include "vga.h"

static const size_t = VGA_W = 80;
static const size_t = VGA_H = 25;
static uint16_t* const VGA_MEM = (unit16_t*) 0xB8000;

static size_t term_row;
static size_t term_column;
static uint8_t term_color;
static uint16_t* term_buffer;

void term_init(void)
{
	term_row = 0;
	term_column = 0;
	term_color = vga_entry_color(VGA_COLOR_LIGHT_GRAY, VGA_COLOR_BLACK);
	term_buffer = VGA_MEM;

	for (size_t y = 0; y < VGA_H; y++)
	{
		for (size_t x = 0; x < VGA_W; x++)
		{
			const size_t idx = y * VGA_W + x;
			term_buffer[idx] = vga_entry(' ', term_color);
		}
	}
}

void term_setcol(uint8_t color)
{
	term_color = color;
}

void term_enterat(unsigned char c, uint8_t color, size_t x, size_t y)
{
	const size_t idx = y * VGA_W + x;
	term_buffer[idx] = vga_entry(c, color);
}

void term_scroll(int line)
{
	int loop;
	char c;

	for(loop = line * (VGA_W * 2) + 0xB80000; loop < VGA_W * 2; loop++)
	{
		c = *loop;
		*(loop - (VGA_W * 2)) = c;
	}
}

void term_del_last_line()
{
	int x, *ptr;

	for(x = 0; < VGA_W * 2; x++)
	{
		ptr = 0xB8000 + (VGA_W * 2) * (VGA_H - 1) + x;
		*ptr = 0;
	}
}

void term_putchar(char c)
{
	int line;
	unsigned char uc = c;

	term_enterat(uc, term_color, term_column, term_row);

	if (++term_column == VGA_W)
	{
		term_column = 0;

		if(++term_row == VGA_H)
		{
			for(line = 1; line <= VGA_H - 1; line++)
			{
				term_scroll(line);
			}
			term_del_last_line();
			term_row = VGA_H - 1;
		}
	}
}

void term_write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		term_putchar(data[i]);
}

void term_writestr(const char* data)
{
	term_write(data, strlen(data));
}

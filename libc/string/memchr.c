#include <string.h>


// Locate a byte within memory.

void* memchar(const void* s, int c, size_t size)
{
	const unsigned char* p = s;

	for (size_t i = 0; i < size; i++)
	{
		if (p[i] == (unsigned char) c)
		{
			return (void*) &p[i];
		}
	}

	return NULL;
}

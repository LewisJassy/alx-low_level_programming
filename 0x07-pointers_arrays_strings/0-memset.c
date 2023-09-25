#include "main.h"
#include <string.h>

/**
 *  _memset - fill char *s, char b, unsigned int n with constant byte
 * @s: memory to be appointed
 * @b: memory to be appointed
 * @n: integer value
 *
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	k = 0;

	for (k = 0; k < n; k++)
		s[k] = b;

	return (s);
}

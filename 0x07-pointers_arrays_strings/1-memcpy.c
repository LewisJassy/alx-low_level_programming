#include "main.h"
#include <string.h>

/**
 * _memcpy - copy at most `n' characters from `src' into `dest'
 * @dest: destination string
 * @src: source string
 * @n: number of characters
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;

	while (n && (dest[i] = src[i]))
		++i, --n;
	while (n-- > 0)
		dest[i++] = '\0';
	return (dest);
}

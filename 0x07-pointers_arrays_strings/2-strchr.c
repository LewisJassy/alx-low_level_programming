#include "main.h"
#include <string.h>

/**
 * _strchr - locating a character of string
 * @s: string to be located
 * @c: string to be located
 *
 * Return: NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		++s;
	}
	if (*s == c)
		return (s);
	return (0);
}

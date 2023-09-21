#include "main.h"
#include <string.h>

/**
 * _strcmp - compare char *s1 and char *s2
 * @s1:string to compare
 * @s2: string to compare
 *
 * Return:s1--s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

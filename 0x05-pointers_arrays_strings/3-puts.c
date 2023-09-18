#include "main.h"
#include <string.h>

/**
 * _puts - print a string, followed by a new line
 *
 * @str: a pointer to a null-terminated string to output.
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

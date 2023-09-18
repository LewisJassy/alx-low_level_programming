#include "main.h"
#include <string.h>

/**
 * puts_half - prints characters of string
 * @str: string
 */

void puts_half(char *str)
{
	int i = 0;
	int n = strlen(str);

	while (str[i] != '\0')
	{
	if (i > (n - 1) / 2)
	{
	_putchar(str[i]);
	}
	i++;
	}
	_putchar('\n');
}

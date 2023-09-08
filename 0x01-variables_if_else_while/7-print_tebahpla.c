#include <stdio.h>
/**
 * main - reversing alphabets
 *
 * Return: 0 always
 */
int main(void)
{
	char i = 'z';

	while (i >= 'a')
	{
		putchar(i--);
	}
	putchar('\n');
	return (0);
}

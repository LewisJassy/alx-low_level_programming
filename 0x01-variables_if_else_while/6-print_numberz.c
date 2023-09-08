#include <stdio.h>
/**
 * main - printint numbers
 *
 * Return: 0 always
 */
int main(void)
{
	int i = '0';

	while (i <= '9')
	{
		putchar(i++);
	}
	putchar('\n');
	return (0);
}

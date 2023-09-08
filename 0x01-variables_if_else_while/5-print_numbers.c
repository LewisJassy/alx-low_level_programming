#include <stdio.h>
/**
 * main - printing numbers from 0 to 9
 *
 * Return: 0 always
 */
int main(void)
{
	char i = '0';

	while (i <= '9')
	{
		putchar(i++);
	}
	putchar('\n');
	return (0);
}

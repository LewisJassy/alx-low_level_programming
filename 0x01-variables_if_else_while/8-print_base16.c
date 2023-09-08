#include <stdio.h>
/**
 * main - print all number base 16
 *
 * Return: 0 always
 */
int main(void)
{
	char c = 0x0;

	while (c <= 0x9)
		putchar('0' + c++);
	while (c <= 0xf)
		putchar('a' - 10 + c++);
	putchar('\n');
	return (0);
}

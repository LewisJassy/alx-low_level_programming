#include <stdio.h>
#include <stdlib.h>
/**
 * main - printing a to z in both lower and upper case
 *
 * Return : 0  always
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
		putchar(c++);
	c = 'A';
	while (c <= 'Z')
		putchar(c++);
	putchar('\n');
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
/**
 * main - printing a to z in both lower and upper case
 *
 * Return : 0  always
 */
int main(void)
{
	char i = 'a';
	char k = 'A';

	while (putchar(i++) < 'z')
		;
	putchar('\n');

	while (putchar(k++) < 'Z')
		;
	putchar('\n');
	return (0);
}

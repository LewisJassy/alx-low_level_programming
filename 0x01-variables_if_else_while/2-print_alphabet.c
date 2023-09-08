#include <stdio.h>
#include <stdlib.h>
/**
 * main - print a to z followed by a newline
 *
 * Return: 0 always
 */
int main(void)
{
	char i =  'a';
	
	while (putchar(i++) < 'z')
		;
	putchar('\n');
	return (0);
}

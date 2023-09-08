#include <stdio.h>
#include <stdlib.h>
/**
 * main - printing alphabets except 'q' and 'e'
 *
 * Return: 0 alwauys
 */
int main(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		if (i != 'e' && i != 'q')
			putchar(i);
		i++;
	}
	putchar('\n');
	return (0);	
}

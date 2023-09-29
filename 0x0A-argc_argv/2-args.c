#include "main.h"
#include <stdio.h>

/**
 * main - print number of arguments
 * @argc: number of arguments
 * @argv: array of pointers to command line arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
	printf("%s\n", argv[i]);
	}
	return (0);
}

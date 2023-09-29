#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - multiply two numbers from command line
 * @argc: number of arguments
 * @argv: array of argumetns
 *
 * Return: 0 for success, 1 if error
 */
int main(int argc, char **argv)
{
	int i, c, sum = 0;

	if (argc == 1)
	{
		puts("0");
		return (0);
	}
	while (--argc)
	{
		++argv;
		for (i = 0; (c = *(*argv + i)); ++i)
		{
			if (!(isdigit(c)))
			{
				puts("Error");
				return (1);
			}
		}
		sum += atoi(*argv);
	}
	printf("%d\n", sum);
	return (0);
}

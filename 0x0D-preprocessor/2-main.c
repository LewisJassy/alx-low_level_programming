#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	char *filename = malloc(100 * sizeof(char));

	if (filename == NULL)
	{
		_exit(1);
	}
	strcpy(filename, __FILE__);
	write(STDOUT_FILENO, filename, strlen(filename));
	write(STDOUT_FILENO, "\n", 1);
	free(filename);
	_exit(0);
}

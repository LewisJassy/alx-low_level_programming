#include "main.h"
#include <stdlib.h>

/**
 * create_array - an array of chars, and initializes it with a specific char.
 * @c: array of characters
 * @size: size of array
 *
 * Return: NULL or a *ptr
 */
char *create_array(unsigned int size, char c)
{
	if (size == 0)
	{
		return NULL;
	}

	char *arr = (char *)malloc(size * sizeof(char));

	if (arr == NULL)
	{
		return NULL;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return arr;
}
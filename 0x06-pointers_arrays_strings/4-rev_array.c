#include "main.h"
#include <string.h>

/**
 * reverse_array - reversing an array of integer
 * @a: array to be reversed
 * @n: length of array
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int j = n - 1;

	while (i < j)
	{
	a[i] = a[i] ^ a[j];
	a[j] = a[i] ^ a[j];
	a[i] = a[i] ^ a[j];
	i++;
	j--;
	}
}


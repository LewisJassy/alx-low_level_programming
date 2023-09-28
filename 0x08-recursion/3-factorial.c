#include "main.h"

/**
 * factorial - printing the factorial of a given number
 * @n: integer to be factorialized
 *
 * Return: -1
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}

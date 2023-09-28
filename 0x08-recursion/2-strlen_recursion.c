#include "main.h"

/**
 * _strlen_recursion - printing the length of a string
 * @s: string to be determined its length
 *
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if ('\0' == *s)
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

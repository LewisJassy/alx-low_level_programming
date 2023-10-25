#include "lists.h"
#include <stdlib.h>
/**
 * listint_len - a function that return number of elementsin a list
 * @h: pointer to the start of list
 * Return: n
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

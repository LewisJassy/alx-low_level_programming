#include "lists.h"
#include <stdio.h>
/**
 * list_len - to return the number of element in a linked list
 * @h: pointer to the element
 * Return: len
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}

#include "lists.h"
#include <stdlib.h>
/**
 * print_listint - printing elements of a list
 * @h:pointer to the start of a list
 * Return:0
 */
size_t print_listint(const listint_t *h)
{
	size_t n;

	n = 0;
	while (h != NULL)
	{
		if (h == NULL)
		{
			return (0);
		}
		else
		{
			printf("%d\n", h->n);
		}
		h = h->next;
		n++;
	}
	return (n);
}

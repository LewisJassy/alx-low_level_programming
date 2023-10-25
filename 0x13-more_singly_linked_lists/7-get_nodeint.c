#include "lists.h"
#include <stdlib.h>
/**
 * get_nodeint_at_index - function to return the nth node of a list
 * @head: pointer to the start of the list
 * @index:initialized integer
 * Return: NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	for (j = 0; head != NULL; ++j)
	{
		if (j == index)
			return (head);
		head = head->next;
	}
	return (NULL);
}

#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - adding a new node at the end of a list
 * @head: pointer to the start of the line
 * @n: interger to be initialized
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *current_node;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
		current_node = *head;

	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new;

	return (new);
}

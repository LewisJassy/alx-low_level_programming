#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint - adding a new node at the begginingof a list
 * @head:pointer to the start of list
 * @n: node to be added
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

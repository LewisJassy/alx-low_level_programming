#include "lists.h"
#include <stdlib.h>
/**
 * pop_listint -deleting the head node and returning the head nodes data (n)
 * @head: pointer to pointer of the list
 * Return:0
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *point;

	if (head == NULL || *head == NULL)
		return (0);

	n = (*head)->n;
	point = (*head)->next;
	free(*head);
	*head = point;

	return (n);
}

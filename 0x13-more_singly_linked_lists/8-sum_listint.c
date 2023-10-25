#include "lists.h"
#include <stdlib.h>
/**
 * sum_listint - function thatb  return sum of data n
 * @head: pointer to the start of the list
 * Return: 0
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

#include "lists.h"
/**
 * free_list - frees all elements in a linked list
 * @head: pointer to head element of list
 *
 * Return: always void
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while ((current_node = head) != NULL)
	{
		head = head->next;
		free(current_node->str);
		free(current_node);
	}
}

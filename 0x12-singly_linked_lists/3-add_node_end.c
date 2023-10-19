#include "lists.h"
#include <string.h>
/**
 * add_node_end - add new new to the end of list pointed to by `head'
 * @head: pointer to the statr of the list
 * @str: pointer to string
 * Return: address of new element, or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	size_t i = 0;
	list_t *last = *head;
	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->str = strdup(str);
	if (new->str)
		while (str[i])
			++i;
	new->len = i;
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*head = new;
	return (new);
}

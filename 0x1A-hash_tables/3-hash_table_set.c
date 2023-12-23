#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - add new entry to hash table
 * @ht: pointer to hash table
 * @key: key to hash into index and store in node
 * @value: value to add to new node
 *
 * Return: 1 if successful, 0 if malloc fails.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int key_i = 0;
	char *val_copy = NULL, *key_copy = NULL;
	hash_node_t *new_node = NULL, *temp_node = NULL;

	if (!ht || !key || !value)
		return (0);
	else if (strlen(key) == 0)
		return (0);
	val_copy = strdup(value);
	if (!val_copy)
		return (0);
	key_copy = strdup(key);
	if (!key_copy)
	{
		free(val_copy);
		return (0);
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(key_copy);
		free(val_copy);
		return (0);
	}
	new_node->key = key_copy;
	new_node->value = val_copy;
	new_node->next = NULL;
	key_i = key_index((unsigned char *)key, ht->size);
	/* COLLISION OCCURED */
	if ((ht->array)[key_i] != NULL)
	{
		temp_node = (ht->array)[key_i];
		while(temp_node)
		{
			if (strcmp(temp_node->key, key_copy) == 0)
			{
				free(ht->array[key_i]->value);
				ht->array[key_i]->value = val_copy;
				free(key_copy);
				free(new_node);
				return (1);
			}
			temp_node = temp_node->next;
		}
		temp_node = (ht->array)[key_i];
		new_node->next = temp_node;
		(ht->array)[key_i] = new_node;
	}
	else
		(ht->array)[key_i] = new_node;
	return (1);
}
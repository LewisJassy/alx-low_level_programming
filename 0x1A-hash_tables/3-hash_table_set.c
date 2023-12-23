#include "hash_tables.h"

/**
 * free_node - Free a node.
 * @node: Node to free.
 *
 * Return: Void.
 */
void free_node(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * hash_table_set - Set a value in the hash table.
 * @ht: Hash table.
 * @key: Key to be indexed.
 * @value: Value to set in the hash table.
 *
 * Return: 1 if works, 0 if doesn't.
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
		while (temp_node)
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

/**
 * create_node - creates a new hash node
 * @key: key for the new node
 * @value: value for the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
    hash_node_t *new_node = malloc(sizeof(hash_node_t));

    if (!new_node)
        return (NULL);

    new_node->key = strdup(key);
    if (!new_node->key)
    {
        free(new_node);
        return (NULL);
    }

    new_node->value = strdup(value);
    if (!new_node->value)
    {
        free(new_node->key);
        free(new_node);
        return (NULL);
    }

    new_node->next = NULL;
    return (new_node);
}

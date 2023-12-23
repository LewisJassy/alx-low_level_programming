#include "hash_tables.h"
#include <stdlib.h>

/**
 * sorted_list_insert - function to insert new node into list
 * alphanumerically by key.
 * @ht: pointer to hash table
 * @new: new node to be inserted
 */
void sorted_list_insert(hash_table_t *ht,hash_node_t *new)
{
	hash_node_t *head = ht->head;

	if (head == NULL)
	{
		ht->head = ht->tail = new;
		new->next = new->prev = NULL;
		return;
	}
	do {
		if (strcmp(new->key, head->key) < 0)
		{
			new->next = head;
			new->prev = head->prev;
			if (head->prev == NULL)
				ht->head = new;
			else
				head->prev->next = new;
			head->prev = new;
			return;
		}
		head = head->next;
	} while (head);
	new->prev = ht->tail;
	new->next = ht->tail->next;
	ht->tail->next = new;
	ht->tail = new;
}

/**
 * create_hash_node - function to create new sorted hash table node
 * @key: key to use (mallocated by calling function).
 * @value: value associated with key (also mallocated by calling function).
 *
 * Return: pointer to new node
 */
hash_node_t *create_hash_node(char *key, char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(key);
		free(value);
		return (NULL);
	}
	new->key = key;
	new->value = value;
	return (new);
}

/**
 * hash_table_create - function to allocate and initialize new sorted
 * hash table.
 * @size: size of array to allocate.
 *
 * Return: pointer to new hash table instance
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	memset(ht->array, 0, sizeof(hash_node_t *) * size);
	ht->size = size;
	ht->head = ht->tail = NULL;
	return (ht);
}

/**
 * hash_table_set - function to set new table element
 * @ht: pointer to hash table
 * @key: key to use
 * @value: value to associate with key
 *
 * Return: 1 on success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *keydup, *valdup;
	hash_node_t *new, *bucket;
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || key == NULL || *key == '\0')
		return (0);
	keydup = strdup(key);
	if (keydup == NULL)
		return (0);
	valdup = strdup(value);
	if (valdup == NULL)
	{
		free(keydup);
		return (0);
	}
	index = key_index((unsigned char *) keydup, ht->size);
	for (bucket = ht->array[index]; bucket != NULL; bucket = bucket->next)
		if (strcmp(keydup, bucket->key) == 0)
		{
			free(bucket->key);
			free(bucket->value);
			bucket->key = keydup;
			bucket->value = valdup;
			return (1);
		}
	new = create_hash_node(keydup, valdup);
	if (new == NULL)
		return (0);
	new->next = ht->array[index];
	ht->array[index] = new;
	sorted_list_insert(ht, new);
	return (1);
}

/**
 * hash_table_get - function to get sorted hash table element by key
 * @ht: pointer to sorted hash table
 * @key: key to search
 *
 * Return: value associated with key
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *bucket;
	unsigned long int index;
	char *keydup;

	if (ht == NULL || key == NULL)
		return (NULL);
	keydup = strdup(key);
	if (keydup == NULL)
		return (NULL);
	index = key_index((const unsigned char *) key, ht->size);
	for (bucket = ht->array[index]; bucket != NULL; bucket = bucket->next)
		if (strcmp(keydup, bucket->key) == 0)
		{
			free(keydup);
			return (bucket->value);
		}
	free(keydup);
	return (NULL);
}

/**
 * hash_table_print - function to print sorted hash table in alphanumeric
 * order.
 * @ht: pointer to sorted hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	char many = 0;

	if (ht == NULL)
		return;
	putchar('{');
	node = ht->head;
	while (node)
	{
		if (many)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		many = 1;
		node = node->next;
	}
	printf("}\n");
}

/**
 * hash_table_print_rev - function to print sorted hash table in
 * reverse alphanumeric order.
 * @ht: pointer to sorted hash table
 */
void hash_table_print_rev(const hash_table_t *ht)
{
	hash_node_t *node;
	char many = 0;

	if (ht == NULL)
		return;
	putchar('{');
	node = ht->tail;
	while (node)
	{
		if (many)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		many = 1;
		node = node->prev;
	}
	printf("}\n");
}

/**
 * hash_table_delete - function to free hash table
 * @ht: pointer to sorted hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *head, *next;

	if (ht == NULL || ht->array == NULL)
		return;
	head = ht->head;
	while (head)
	{
		next = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = next;
	}
	free(ht->array);
	free(ht);
}

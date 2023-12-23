#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - sets a hash table key value pair in hash table
 * @ht: hash table to set in
 * @key: key to generate hash value and index off
 * @value: value to set as hash_node's value
 *
 * Return: (1) success, (0) failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int key_i = 0;

    if (!ht || !key || !value || strlen(key) == 0)
        return (0);

    key_i = key_index((unsigned char *)key, ht->size);

    if (update_existing_node(ht, key_i, key, value))
        return (1);

    if (handle_collision(ht, key_i, key, value))
        return (1);

    return (1);
}

/**
 * update_existing_node - updates value of an existing key in the hash table
 * @ht: hash table to set in
 * @key_i: index in the array to place the hash_node
 * @key: key to generate hash value and index off
 * @value: value to set as hash_node's value
 *
 * Return: (1) success, (0) failure
 */
int update_existing_node(hash_table_t *ht, unsigned long int key_i,
                          const char *key, const char *value)
{
    hash_node_t *temp_node = ht->array[key_i];

    while (temp_node)
    {
        if (strcmp(temp_node->key, key) == 0)
        {
            free(temp_node->value);
            temp_node->value = strdup(value);
            return (1);
        }
        temp_node = temp_node->next;
    }
    return (0);
}

/**
 * handle_collision - handles collision by adding a new node
 * @ht: hash table to set in
 * @key_i: index in the array to place the hash_node
 * @key: key to generate hash value and index off
 * @value: value to set as hash_node's value
 *
 * Return: (1) success, (0) failure
 */
int handle_collision(hash_table_t *ht, unsigned long int key_i,
                     const char *key, const char *value)
{
    hash_node_t *new_node = create_node(key, value);

    if (!new_node)
        return (0);

    new_node->next = ht->array[key_i];
    ht->array[key_i] = new_node;
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

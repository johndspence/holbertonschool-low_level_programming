#include "hash_tables.h"

/**
 * hash_table_set - Adds an key/value to a hash table.
 * @ht: Pointer to the hash table.
 * @key: Key to be added.
 * @value: Value to be added.
 * Return: 1 if success, 0 if otherwise.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	hash_node_t *temp_node_ptr;
	unsigned long int index;

	if (!ht || !key || !value || strlen(key) == 0)
	{
		return (0);
	}

	index = key_index((unsigned char *)key, ht->size);
	
	if (ht->array[index])
	{
		temp_node_ptr = ht->array[index];
		while (temp_node_ptr && strcmp(temp_node_ptr->key, key) != 0)
		{
			temp_node_ptr = temp_node_ptr->next;
		}
		if (temp_node_ptr && strcmp(temp_node_ptr->key, key) == 0)
		{
			free(temp_node_ptr->value);
			temp_node_ptr->value = strdup(value);
			return (1);
		}
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		return(0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

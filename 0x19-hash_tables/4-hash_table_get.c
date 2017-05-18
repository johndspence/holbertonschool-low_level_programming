#include "hash_tables.h"

/**
 * hash_table_get - returns a value associated with a key from a hash table.
 *
 * @ht: Hash table to be searched.
 * @key: key to search
 * Return: Returns pointer to value associated with key or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp_node_ptr;
	int key_len;

	if (!ht || !key || !ht->array)
		return (NULL);
	key_len = strlen(key);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index])
	{
		temp_node_ptr = ht->array[index];
		while (temp_node_ptr && strncmp(temp_node_ptr->key, key, key_len) != 0)
		{
			temp_node_ptr = temp_node_ptr->next;
		}
		if (temp_node_ptr && strncmp(temp_node_ptr->key, key, key_len) == 0)
		{
			return (temp_node_ptr->value);
		}
	}
	return (NULL);
}

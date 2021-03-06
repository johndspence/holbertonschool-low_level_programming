#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with chaining.
 * @size: number of elements in the hash table array.
 *
 * Return: a pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hash_table_ptr;

	if (size == 0)
	{
		return (NULL);
	}
	hash_table_ptr = NULL;
	hash_table_ptr = malloc(sizeof(hash_table_t));
	if (hash_table_ptr == NULL)
	{
		free(hash_table_ptr);
		return (NULL);
	}
	hash_table_ptr->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table_ptr->array == NULL)
	{
		free(hash_table_ptr->array);
		return (NULL);
	}
	hash_table_ptr->size = size;
	for (i = 0; i < hash_table_ptr->size; i++)
	{
		hash_table_ptr->array[i] = NULL;
	}
	return (hash_table_ptr);
}

#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table of size.
 * @size: size of the array of each hash node.
 * Return: a pointer to the newly created hash table.
 * Steps:
 * 1. Create instance of HashTable using malloc
 * 2. Create instance of array to hold pointers to List nodes,
 *    also using malloc respecting size
 * 3. Populate size of this instance of HashTable
 * 4. Populate array of this instance of HashTable
 * 5. Return pointer to this instance of HashTable
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table_ptr;
	hash_node_t **array;
	unsigned long int i;

	if (size == 0)
	{
		return (NULL);
	}
	array = malloc(sizeof(*array) * size);
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		array[i] = NULL;
	}
	hash_table_ptr = malloc(sizeof(hash_table_t));
	if (hash_table_ptr == NULL)
	{
		return (NULL);
	}

	hash_table_ptr->size = size;
	hash_table_ptr->array = array;
	return (hash_table_ptr);
}

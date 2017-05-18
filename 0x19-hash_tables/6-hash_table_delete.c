#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a  hash table.
 * @ht: Hash table to be deleted.
 *
 * Return: Void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current_node_ptr;
	hash_node_t *temp_node_ptr;

	if (!ht)
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		current_node_ptr = ht->array[i];
		while(current_node_ptr)
		{
			temp_node_ptr = current_node_ptr;
			current_node_ptr = current_node_ptr->next;
			free(temp_node_ptr->key);
			free(temp_node_ptr->value);
			free(temp_node_ptr);
			temp_node_ptr = NULL;
		}
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
	ht = NULL;
}

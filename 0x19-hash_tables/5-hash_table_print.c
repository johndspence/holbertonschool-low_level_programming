#include "hash_tables.h"

/**
 * hash_table_print - prints key value pairs from a hash table in json format.
 *
 * @ht: hash_table_t to be searched and printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp_node_ptr;
	char *flag;

	flag = "";
	if (!ht)
		return;
	printf("{");
	if (!ht->array)
	{
		printf("}\n");
		return;
	}
	for (i = 0; i < ht->size; i++)
	{
		temp_node_ptr = (ht->array[i]);
		while (temp_node_ptr != NULL)
		{

			printf("%s'%s': '%s'", flag, temp_node_ptr->key, temp_node_ptr->value);
			temp_node_ptr = temp_node_ptr->next;
			flag = ", ";
		}
	}
	printf("}\n");
}

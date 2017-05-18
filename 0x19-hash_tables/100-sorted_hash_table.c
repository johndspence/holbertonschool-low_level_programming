#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table with chaining.
 * @size: number of elements in the hash table array.
 *
 * Return: a pointer to the newly created hash table.
 *
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_hash_table_ptr;
	unsigned long int i;

	if (size == 0)
	{
		return (NULL);
	}
	new_hash_table_ptr = malloc(sizeof(shash_table_t));
	if (new_hash_table_ptr == NULL)
	{
		free(new_hash_table_ptr);
		return (NULL);
	}
	new_hash_table_ptr->array = calloc(size, sizeof(shash_node_t *));
	if (new_hash_table_ptr->array == NULL)
	{
		free(new_hash_table_ptr->array);
		return (NULL);
	}
	new_hash_table_ptr->size = size;
	return (new_hash_table_ptr);
}

/**
 * linked_list_sort - sorts a linked list.
 *
 *
 */
/*void sort_linked_list(shash_table_t *ht, unsigned long index)
{
	return;
}*/

/**
 * shash_table_set - Adds a key/value to a hash table.
 * @ht: Pointer to the hash table.
 * Compile: gcc -Wall -pedantic -Werror -Wextra 0-hash_table_create.c 3-main.c
 * 2-key_index.c 1-djb2.c 3-hash_table_set.c -o c
 * @key: Key to be added.
 * @value: Value to be added.
 * Return: 1 if success, 0 if otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;
	shash_node_t *temp_node_ptr;
	unsigned long int index;

	if (!ht || !key || !value || strlen(key) == 0)
		return (0);
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
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
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
	/* INSERT SORT FUNCTION HERE */
	return (1);

/**
 * shash_table_get - returns a value associated with a key from a hash table.
 *
 * @ht: Hash table to be searched.
 * @key: key to search
 * Return: Returns pointer to value associated with key or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp_node_ptr;
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

/**
 * hash_table_print - prints key value pairs from a hash table in json format.
 *
 * @ht: hash_table_t to be searched and printed.
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *temp_node_ptr;
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
		temp_node_ptr = (ht->array[i]);/* CHECK THIS */
		while (temp_node_ptr != NULL)
		{

			printf("%s'%s': '%s'", flag, temp_node_ptr->key, temp_node_ptr->value);
			temp_node_ptr = temp_node_ptr->next;/* CHECK THIS */
			flag = ", ";
		}
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a hash table.
 * @ht: Hash table to be deleted.
 *
 * Return: Void.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current_node_ptr;
	shash_node_t *temp_node_ptr;

	if (!ht)
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		current_node_ptr = ht->array[i];
		while (current_node_ptr)
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

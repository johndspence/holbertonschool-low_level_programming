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

	new_hash_table_ptr = malloc(sizeof(shash_table_t));
	if (size < 1 || !new_hash_table_ptr)
	{
		return (NULL);
	}
	new_hash_table_ptr->array = malloc(sizeof(shash_node_t *) * size);
	if (new_hash_table_ptr->array == NULL)
	{
		/**
		 *free(new_hash_table_ptr->array);
		 *free(new_hash_table_ptr);
		 */
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		new_hash_table_ptr->array[i] = NULL;
	}
	new_hash_table_ptr->size = size;
	new_hash_table_ptr->shead = NULL;
	new_hash_table_ptr->stail = NULL;
	printf("HASH TABLE CREATED\n");
	return (new_hash_table_ptr);
}

/**
 * insert_sort - inserts a new node into a linked list and sorts.
 * @ht: hash_table
 * @new: new hash table pointer.
 * @tmp: temp node pointer
 *
 * Return: void.
 */
void insert_sort(shash_table_t *ht, shash_node_t *new, shash_node_t *tmp)
{
	shash_node_t *pre;

	pre = new;
	if (!ht->shead) /* if no nodes in sorted list */
	{
		ht->shead = new;
		ht->stail = new;

		new->sprev = NULL;
		new->snext = NULL;
	}
	else /* add and sort new node */
	{
		tmp = ht->shead;
		while (tmp->snext && strcmp(new->key, tmp->key) > 0)
		{
			tmp = tmp->snext;
		}
		if (tmp == ht->shead && ht->stail != tmp)
		{
			ht->shead = new;
			new->snext = tmp;
			new->sprev = NULL;
			tmp->sprev = new;
		}
		else if (!tmp->snext && strcmp(new->key, tmp->key) > 0)
		{
			tmp->snext = new;
			new->sprev = tmp;
			new->snext = NULL;
			ht->stail = new;
		}
		else
		{
			pre = tmp->sprev;
			pre->snext = new;
			new->snext = tmp;
			new->sprev = pre;
			tmp->sprev = new;
		}
	}
}

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

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	if (ht->array[index] != NULL)
	{
		temp_node_ptr = ht->array[index];
		if (temp_node_ptr != NULL && (strcmp(temp_node_ptr->key, key) == 0))
		{
			temp_node_ptr->value = strdup(value);
			return (1);
		}
	}
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->snext = ht->array[index];
	ht->array[index] = new_node;
	/* INSERT SORT FUNCTION HERE */
	insert_sort(ht, new_node, temp_node_ptr);
	return (1);
}

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

	temp_node_ptr = (ht->shead);
	if (!ht || !key || !temp_node_ptr)
		return (NULL);
	key_len = strlen(key);

	index = key_index((const unsigned char *)key, key_len);

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
 * shash_table_print - prints key value pairs from a hash table in json.
 *
 * @ht: shash_table_t to be searched and printed.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp_node_ptr;

	if (ht == NULL)
	{
		return;
	}
	printf("{");

	if (ht->array == NULL)
	{
		printf("}\n");
		return;
	}
	temp_node_ptr = ht->shead;
	while (temp_node_ptr != NULL)
	while (temp_node_ptr != NULL)
	{
		if (temp_node_ptr->snext != NULL)
			printf("'%s': '%s', ", temp_node_ptr->key, temp_node_ptr->value);
		else
			printf("'%s': '%s'", temp_node_ptr->key, temp_node_ptr->value);
		temp_node_ptr = temp_node_ptr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints key value pairs from a hash table in json.
 *
 * @ht: hash_table_t to be searched and printed.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp_node_ptr;
	char *flag;

	flag = "";
	if (!ht)
		return;
	temp_node_ptr = ht->stail;
	printf("{");
	if (!temp_node_ptr)
	{
		printf("}\n");
		return;
	}
	while (temp_node_ptr != NULL)
	{
		while (temp_node_ptr->sprev != NULL)
		{
			printf("%s'%s': '%s'", flag, temp_node_ptr->key, temp_node_ptr->value);
			temp_node_ptr = temp_node_ptr->sprev;
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
			current_node_ptr = current_node_ptr->snext;
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

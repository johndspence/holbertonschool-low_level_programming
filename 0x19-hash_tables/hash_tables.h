#ifndef HASHTABLES
#define HASHTABLES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct List - hash node s
 * @key : The key string of a pair
 * The key is unique in the HashTable
 *
 * @value : The value corresponding to a key
 * A value is not unique. It can correspond to several keys
 *
 * @next : A pointer to the next node of the List
 */
typedef struct List
{
	char *key;
	char *value;
	struct List *next;
} List;

/**
 * struct hash_table_t - hash table
 * @size : The size of the array
 *
 * @array : An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_t
{
	unsigned long int size;
	List **array;
} hash_table_t

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);

#endif /* HASHTABLES */

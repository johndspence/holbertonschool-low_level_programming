#include "hash_tables.h"

/**
 * key_index - Function that gives the index of a key for a hash table using a
 * hash function.
 *
 * @key: Pointer to *char string holding Key to find index for.
 * @size: Size of the array of indexes in the hash table.
 *
 * Return: Index value corresponding to the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

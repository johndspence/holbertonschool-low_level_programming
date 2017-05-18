#ifndef _HASHTABLE_H_
#define _HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct List
{
	char *key;
	char *value;
	struct List *next;
} List;

typedef struct hash_table_t
{
	unsigned long int size;
	List **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);


#endif

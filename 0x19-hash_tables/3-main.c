#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "holberton");
	hash_table_set(ht, "hetairas", "holberton");
	hash_table_set(ht, "heliotropes", "holberton");
	hash_table_set(ht, "depravement", "holberton");
	hash_table_set(ht, "neurospora", "holberton");
	hash_table_set(ht, "stylist", "holberton");
	hash_table_set(ht, "joyful", "holberton");
	hash_table_set(ht, "serafins", "holberton");
	hash_table_set(ht, "subgenera", "holberton");
	hash_table_set(ht, "urites", "holberton");
	hash_table_set(ht, "dram", "holberton");
	hash_table_set(ht, "vivency", "holberton");
	return (EXIT_SUCCESS);
}

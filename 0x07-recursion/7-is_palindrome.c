#include "holberton.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * @i: integer to iterate with
 * Return: length of string
 */
int _strlen(char *s, int i)
{
	if (*s == '\0')
	{
		return (i);
	}
	return (_strlen(s + 1, i + 1));
}

/**
* palindrome_iterator - returns 1 if a string is a palindrome and 0 if not,
* using recursion.
* @s: string to be evaluated.
* @len: length of string.
* Return: 1 or 0 (int).
*/
int palindrome_iterator(char *s, int len)
{
	if (len == 0 || len == 1)
	{
		return (1);
	}
	if (*s != s[len - 1])
	{
	return (0);
	}
	else
	{
	return (palindrome_iterator(s + 1, len - 2));
	}
}

/**
* is_palindrome - returns 1 if a string is a palindrome and 0 if not.
* @s: string to be evaluated.
* Return: 1 or 0.
*/
int is_palindrome(char *s)
{
	int i;
	int len;

	i = 0;
	len = _strlen(s, i);

	return (palindrome_iterator(s, len));
}

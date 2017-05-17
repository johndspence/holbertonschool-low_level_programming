#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if the strings can be
 * considered identical, otherwise returns 0, using recursion.
 * @s1: string 1.
 * @s2: string 2, which can contain the wildcard "*".
 * Return: 1 if strings identical and 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
	{
		if (*(s1 + 1) == *(s2 + 1))
		{
			return (wildcmp(s1 + 1, s2 + 1));
		}
		if (wildcmp(s1, s2 + 1))
		{
			return (1);
		}
		if (wildcmp(s1 + 1, s2))
		{
			return (1);
		}
		if (*(s1 + 1) != '\0' && *s2 == '\0')
		{
			return (0);
		}
	}
	return (0);
}

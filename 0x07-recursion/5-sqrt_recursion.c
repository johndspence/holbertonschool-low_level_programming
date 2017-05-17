#include "holberton.h"

/**
 * sqrt_iterate - returns the natural square root of a number.
 * @n: A number.
 * @i: Exponent.
 *
 * Return: Natural square root of a number (int).
 */
int sqrt_iterate(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (sqrt_iterate(n, i + 1));
}

/**
* _sqrt_recursion - returns the natural square root of a number using
 * recursion.
 * @n: A number.
 *
 * Return: Square root of a number (int).
 */
int _sqrt_recursion(int n)
{
	int i;

	i = 0;

	return (sqrt_iterate(n, i));
}

#include "holberton.h"

/**
 * factorial - returns the factorial of a given number using recursion.
 * @n: A number.
 *
 * Return: The factorial of given number (int).
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n <= 1)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}

#include "holberton.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y using
 * recursion.
 *
 * @x: A number, x.
 * @y: An Exponent, y.
 *
 * Return: Value of x^y (int).
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	if (x == 1 || y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, y - 1));
}

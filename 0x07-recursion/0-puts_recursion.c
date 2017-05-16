#include "holberton.h"

/**
 * op_add - Makes the sum of two numbers
 * @arg1: First operand
 * @arg2: Second operand
 *
 * Description: This is a longer description.
 * Don't forget that a line should not exceed 80 characters.
 * But you're totally free to use several lines to properly
 * describe your function
 * Return: The sum of the two parameters
 */

 void _puts_recursion(char *s)
 {
     if(!*s)
     {
         _putchar('\n');
         return;
     }
     _putchar(*s);
     _puts_recursion(s + 1);
 }

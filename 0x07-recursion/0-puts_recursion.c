#include "holberton.h"

/**
 * _puts_recursion - prints a string recursively.
 * @s: string
 *
 * Description: Prints a string recursively followed by new line
 * using write.
 * Return: Void.
 */
 void _puts_recursion(char *s)
 {
     if (!*s)
     {
         _putchar('\n');
         return;
     }
     _putchar(*s);
     _puts_recursion(s + 1);
 }

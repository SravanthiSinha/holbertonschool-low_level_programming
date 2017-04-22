#include "holberton.h"

/**
 * _pow_recursion - recursive implementation of pow
 *
 * @x: base number
 * @y: exponent to raise the base number
 * Return: computed power
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	if (y < 0)
		return (-1);
	return (x * _pow_recursion(x, --y));
}

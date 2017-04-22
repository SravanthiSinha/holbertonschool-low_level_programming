#include "holberton.h"

/**
 * sqrt_cal - helper function for sqrt
 *
 * @n: number to square
 * @c: counter for finding square
 * Return: returns square when completed, or returns itself recursively
 */
int sqrt_cal(int n, int c)
{
	int sum;

	sum = c * c;
	if (n - sum == 0)
		return (c);
	else if (n < sum)
		return (-1);
	return (sqrt_cal(n, ++c));
}

/**
 * _sqrt_recursion - recursive sqrt implementation, for natural sqrs
 *
 *
 * @n: number to square
 * Return: returns -1 if no natural square, otherwise returns square
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 1)
		return (1);
	return (sqrt_cal(n, 2));
}

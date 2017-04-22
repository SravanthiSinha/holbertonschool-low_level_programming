#include "holberton.h"

/**
 * prime_cal - helper function for is_prime_number
 *
 * @n: number to check for primality
 * @c: counter for prime check value
 * Return: returns itself when not finished, when finished returns 1 for prime,
 * or 0 for not
 */
int prime_cal(int n, int c)
{
	if (n % c == 0)
		return (0);
	if (c > (n / 2))
		return (1);
	return (prime_cal(n, ++c));
}

/**
 * is_prime_number - determines if a number is prime
 *
 * @n: number to check
 * Return: returns 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 0)
		return (0);
	if (n % 2 == 0)
		return (0);
	if (n == 1)
		return (0);
	return (prime_cal(n, 3));
}

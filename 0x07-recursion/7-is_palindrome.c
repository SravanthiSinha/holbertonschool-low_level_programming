#include "holberton.h"
#include <stdio.h>

/**
 * palindrome_check - helper function for is_palindrome
 *
 * @l: length of string
 * @i: counter for palindrome
 * @s: string to check
 * Return: returns itself if incomplete, or 1 for palindrome, 0 for not
 */
int palindrome_check(char *s, int l, int i)
{
	if (s[i] == s[l] && l != i)
		return (palindrome_check(s, --l, ++i));
	if (s[i] == s[l] || i >= l)
		return (1);
	if (s[i] != s[l])
		return (0);
	return (1);
}

/**
 * recursive_strlen - recursively checks string length
 *
 * @s: string to check length of
 * @i: counter
 * Return: returns itself if not complete, or length
 */
int recursive_strlen(char *s, int i)
{
	if (s[i] != '\0')
		return (recursive_strlen(s, ++i));
	return (--i);
}

/**
 * is_palindrome - determines if number inside string is a palindrome or not
 *
 *
 *
 * @s: string to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	int length;

	length = recursive_strlen(s, 0);
	return (palindrome_check(s, length, 0));
}

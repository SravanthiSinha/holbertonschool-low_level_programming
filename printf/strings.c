#include "holberton.h"

/**
 * reverse - A function to reverse the string
 * @str: string to be reversed
 * @length: length of the @str to be reversed
 */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		swap(&(str[start]), &(str[end]));
		start++;
		end--;
	}
}

/**
 * string_concat - concatinates the given 2 strings
 * @s1: string to be concatinated
 * @s2: string to be concatinated
 * Description: concatinates the given 2 strings
 * Return: concatinated string
 */
char *string_concat(char *s1, char *s2)
{

	int len, len2, i, j;
	char *s;

	i = 0;
	j = 0;
	len = str_len(s1);
	len2 = str_len(s2);
	s = malloc(sizeof(*s) * (len + len2 + 1));
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * str_len - A function which returns the length of the string.
 * @str: string whose length is measured.
 * Description: returns the length of the string @str.
 * Return: length of the @str
 */
int str_len(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * str_ncomp - Compare characters of two strings
 * @s1: C string to be compared.
 * @s2: C string to be compared.
 * @k: Maximum number of characters to compare
 * Description:Compares up to k characters of the C string s1
 * to those of the C string s2.
 * Return: An integral value indicating the relationship
 * between the strings
 */
int str_ncomp(char *s1, char *s2, int k)
{
	int i;
	int n1;
	int n2;
	int t;
	int n;

	i = 0;
	t = 0;
	n1 = str_len(s1);
	n2 = str_len(s2);
	n = (n1 >= n2) ? n1 : n2;
	n = (k > n) ? n : k;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			t = s1[i] - s2[i];
			break;
		}
		else
			t = 0;
		i++;
	}
	return (t);
}

/**
 * string_dup - Creates a duplicate of the string pointed to by str
 * @str: pointer to the null-terminated string to duplicate
 * Description: Creates a duplicate of the string pointed to by str
 * Return: A pointer to the newly allocated string,
 * or a null pointer if an error occurred.
 */
char *string_dup(char *str)
{
	int len;
	int i;
	char *s;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = str_len(str);
	s = malloc(sizeof(*s) * (len + 1));
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

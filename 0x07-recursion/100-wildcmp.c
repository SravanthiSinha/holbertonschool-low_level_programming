/**
* match_strings- a helper function that compares two strings recursively
* @first:string 1
* @second: string 2
* Description:  a function that compares two strings and returns 1 if the
* strings can be considered identical, otherwise return 0
* Return: 1 if the  strings can be considered identical, otherwise return 0
*/

int match_strings(char *first, char *second)
{

	if (*first == '\0' && *second == '\0')
		return (1);

	if (*second == '*' && *(second + 1) != '\0' && *first == '\0')
		return (0);

	if (*first == *second)
		return (match_strings(first + 1, second + 1));

	if (*second == '*')
		return (match_strings(first + 1, second) ||
			match_strings(first, second + 1));

	return (0);
}

/**
* wildcmp- a function that compares two strings
* @s1:string 1
* @s2: string 2
* Description:  a function that compares two strings and returns 1 if the
* strings can be considered identical, otherwise return 0
* Return: 1 if the  strings can be considered identical, otherwise return 0
*/

int wildcmp(char *s1, char *s2)
{
	return (match_strings(s1, s2) ? 1 : 0);
}

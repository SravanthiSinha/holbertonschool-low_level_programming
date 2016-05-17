#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void reverse(char str[], int length)
{
	int start = 0;
	int end = length -1;
	while (start < end)
	{
		swap(&(str[start]), &(str[end]));
		start++;
		end--;
	}
}

/*
*  a function that concatenates two strings.
*/
char *string_concat(char *s1, char *s2)
{
	
	int len,len2,i,j;
	char *s;
	i = 0;
	j=0;
	len = str_len(s1);
	len2= str_len(s2);
	s = malloc(sizeof(*s) * (len + len2 + 1) );
	if (s == NULL)
		return ( NULL);

	else
	{
		while(i < len)
		{
			s[i]= s1[i];
			i++;
		}
		
		while(j < len2)
		{
			s[i] = s2[j];
			i++;
			j++;
		}
		s[i] = '\0';
	}
	return s;
}


int str_len(char *s)
{
	int i;
	i = 0;
	while(s[i])
		i++;
	return (i);
}


int str_ncomp(char *s1, char *s2, int k)
{
        int i;
	int n1;
	int n2;
	int t;
	int n;
	i = 0;
	t = 0;
	n1=str_len(s1);
	n2=str_len(s2);
	n = (n1 >= n2) ? n1 : n2;
	n = (k > n) ? n : k;
	while(i<n)
	{
		if(s1[i]!=s2[i])
		{
			t=s1[i]-s2[i];
			break;
		}
		else
			t=0;
		i++;
	}
	return (t);
}
/*
* function that returns a pointer to a newly allocated
* space in memory, which contains a copy of the
* string given as a parameter.
*/

char *string_dup(char *str)
{
        int len;
	int i;
	char *s;
	i = 0;
	if (str == NULL)
	        return (NULL);
	else
	{
		len = str_len(str);
		s = malloc(sizeof(*s) * (len + 1));
		while(i<len)
		{
			s[i]=str[i];
			i++;
		}
	}
	s[i]='\0';
	return s;
}

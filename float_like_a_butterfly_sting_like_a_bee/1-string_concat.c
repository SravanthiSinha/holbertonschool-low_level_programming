#include<stdlib.h>
#include<stdio.h>

/* The function str_len takes a string
 * and returns the length of string
 * It takes a argument (char *) and
 * returns an argumenet (int)
 */

int str_len(char *str)
{
  int len = 0;

  while(*(str + len)!='\0')
    {
      len++;
    }

  return len;
}

/*
 *  a function that concatenates two strings.
 */

char *string_concat(char *s1, char *s2)
{
 
  int len,len2,i,j;
  char *s;
  i = 0;
  j = 0;
  len = str_len(s1);
  len2 = str_len(s2);  
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

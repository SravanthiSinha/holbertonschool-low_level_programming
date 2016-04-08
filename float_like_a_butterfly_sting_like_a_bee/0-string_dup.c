#include<stdlib.h>

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
 * function that returns a pointer to a newly allocated 
 * space in memory, which contains a copy of the 
 * string given as a parameter.
 */

char *string_dup(char *str)
{
 
  int len,i;
  char *s;

  i = 0;
  len = str_len(str);
  s = malloc(sizeof(*s) * len);
  
  if (s == NULL)
    {
       return (NULL);
    }
  else
    {
        while(i<len)
	  {
	    s[i]=str[i];
	    i++;
	  }
    }
  return s; 
  
}

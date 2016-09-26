#include <stdlib.h>
#include "list.h"

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
  s = malloc(sizeof(*s) * (len + 1));
  
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
      s[i] = '\0';
    }
  return s; 
  
}


/*a function that allocates 
  a new node and links it to the to a list*/
int add_node(List **list, char *content)
{
  List *head;
  List *node;
  
  head = *list;        
  node = malloc(sizeof(List));
  if(node == NULL)
    return (1);
  else 
    {
      node->str = string_dup(content);
      node->next = head;
      *list = node;
      return (0);
    }  
  return 1;
}

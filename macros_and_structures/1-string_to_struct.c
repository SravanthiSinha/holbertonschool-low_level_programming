#include<stdlib.h>
#include "str_struct.h"

int str_len(char *s)
{
  int i;

  while(s[i]!='\0')
    {
      i++; 
    }
  return i;
}


/*A function that stores a string 
  and its length in a structure
  and return the address of this structure*/
struct String *string_to_struct(char *str)
{
   
  struct String *string;

  string = malloc(sizeof(struct String));
  if (string == NULL)
    {
      return (NULL);
    }
  string->str = str;
  string->length = str_len(str);  
  return string;
}

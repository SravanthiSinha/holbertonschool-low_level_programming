#include <stdlib.h>
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

/* The function string_copy
 * copies a string.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */

char *string_copy(char * dest, char *src)
{
  int i;

  i=0;
  while((*(src+i)!='\0'))
    {
      *(dest+i)=*(src+i);
      i++;
    }
  *(dest+i)='\0';
  return dest  ;
}

/*A function that stores a string 
  and its length in a structure
  and return the address of this structure*/
struct String *string_to_struct(char *str)
{
   
  struct String *string;
  int len;

  string = malloc(sizeof(struct String));
  if (string == NULL)
    {
      return (NULL);
    }
  len=str_len(str);
  string->str = malloc((len + 1)*sizeof(char));
  string_copy(string->str,str);
  string->length = len;
  return string;
}

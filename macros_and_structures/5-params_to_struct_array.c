#include <stdlib.h>
#include "param_struct.h"

int str_len(char *str);
char **string_split(char *str);
/* The function string_copy
 * copies a string.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */

char *string_copy(char * dest,char *src)
{
  int i;

  i=0;
  while((*(src+i) != '\0'))
    {
      *(dest+i) = *(src+i);
      i++;
    }
  *(dest+i) = '\0';
  return dest  ;
}

/* A fucntion that stores the program’s parameters in an array 
  of structures and returns the address of the first cell of the array*/
struct Param *params_to_struct_array(int ac, char **av)
{

  struct Param *param;

  int i;
  int len;
 
  param =(struct Param *) malloc((ac + 1) * sizeof(struct Param));

  for( i = 0 ; i < ac; i++)
    {
      param[i].str = av[i];
      len = str_len(av[i]);
      param[i].length = len;
      param[i].copy = malloc((len) * sizeof(char));
      string_copy(param[i].copy, av[i]);
      param[i].tab=string_split(av[i]);
    }
      param[i].str = NULL;

  return param;
}

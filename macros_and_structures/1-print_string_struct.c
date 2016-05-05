#include<stdio.h>
#include "str_struct.h"

struct String *string_to_struct(char *str);
/* prints the conenets of sturcture String
   it takes struct String
   has no output arguement*/
void print_string_struct(struct String *str)
{
  if(str!=NULL)
    printf("%s, %d\n",str->str,str->length);
  else 
    printf("No struct to print");
}


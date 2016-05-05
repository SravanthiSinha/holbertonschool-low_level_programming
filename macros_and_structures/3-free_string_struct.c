#include <stdlib.h>
#include "str_struct.h"

void free_string_struct(struct String *str)
{
  char *p;
  if(str!=NULL)
    {
      p=str->str;
      free(p);
      free(str);
    }
}

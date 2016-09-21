#include <stdlib.h>
#include "list.h"

int add_end_cl_list(List **, char *);

List *array_to_cl_list(char **array)
{
  List *list;

  list = NULL;
  
  while(*array)
    {
      add_end_cl_list(&list, *array);
      array++;
    }
  if (list)
    return list;
  return NULL;
}

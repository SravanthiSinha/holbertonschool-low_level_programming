#include <stdlib.h>
#include "list.h"

int add_end_dcl_list(List **, char *);

List *array_to_dcl_list(char **array)
{
  List *list;

  list = NULL;
  
  while(*array)
    {
      add_end_dcl_list(&list, *array);
      array++;
    }

  return list;
}

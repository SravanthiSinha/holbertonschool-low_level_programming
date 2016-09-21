#include <stdlib.h>
#include "list.h"

int add_end_dl_list(List **, char *);

List *array_to_dl_list(char **array)
{
  List *list;

  list = NULL;
  
  while(*array)
    {
      add_end_dl_list(&list, *array);
      array++;
    }

  return list;
}

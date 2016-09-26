#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *content);
List *array_to_list(char **a)
{
  
  List *list;
  int i;
  list = NULL;
  for(i = 0; a[i]; i++)
    {
      add_node(&list,a[i]);
    }
  
  return list;

}

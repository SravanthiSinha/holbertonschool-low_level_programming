#include <stdlib.h>
#include "list.h"

void free_list(List *list)
{
  
  List *node;  
  node = list; 
  while(node != NULL)
    {
      free(node->str);
      free(node);
      node = node->next;
    }

}

#include <stdlib.h>
#include "list.h"

void free_dl_list(List *head)
{
  List *node;
  List *curr;
  node = head;
  while(node)
    {
      curr = node;
      node = node->next;
      free(curr->str);
      free(curr);      
    }
}

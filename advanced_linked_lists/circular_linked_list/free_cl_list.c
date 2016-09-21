#include <stdlib.h>
#include "list.h"

void free_cl_list(List *head)
{
  List *node;
  List *curr;
  node = head;
  while(node->next!=head)
    {
      curr = node;
      node = node->next;
      free(curr->str);
      free(curr);      
    }
  if(node)
    {
      curr = node;
      free(curr->str);
      free(curr);      
    }
}

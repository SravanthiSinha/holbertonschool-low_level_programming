#include "list.h"
#include "stdlib.h"

void free_dcl_list(List *head)
{
  List *node;
  List *curr;
  node = head;
  while(node->next != head)
    {
      curr = node;
      node = node->next;
      free(curr->str);
      free(curr);      
    }
  if(node)
    {
      curr = node;
      node = node->next;
      free(curr->str);
      free(curr);      
    }
}

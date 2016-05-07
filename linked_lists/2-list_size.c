#include <stdlib.h>
#include "list.h"

int list_size(List *list)
{
  List *node;
  int size;
  
  size = 0;
  node = list;
  while(node!= NULL)
    {
      size++;
      node = node->next;
    }
  
  return (size);
}

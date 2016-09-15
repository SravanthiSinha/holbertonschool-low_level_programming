#include <stdlib.h>
#include "list.h"
void free_list(List *head)
{
  List *node;
  List *temp;
  node = head;
  while(node!=NULL)
    {
      temp = node;      
      node = node->next;
      free(temp->str);
      free(temp); 
    }
}

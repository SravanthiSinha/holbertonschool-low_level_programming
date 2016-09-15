#include <stdlib.h>
#include "list.h"
#include <malloc.h>


void remove_from_list(List **head, int index)
{
  List *node;
  List *curr;
  int i;

  node = *head;
  i = 0;
  while(node->next != NULL)
    {
      curr = node;
      node = node->next;
      i++;
      if(i == index)
	break;
    }
  curr->next=node->next;
}

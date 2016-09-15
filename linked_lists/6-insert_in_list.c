#include <stdlib.h>
#include "list.h"
#include <malloc.h>

char *string_dup(char *str);
int insert_in_list(List **head, char *content, int index)
{
  List *node;
  List *curr;
  List *temp;
  int i;

  node = *head;
  i = 0;
  while(node->next != NULL)
    {
      i++;
      if(i == index)
	break;
      node = node->next;
    }
  temp = malloc(sizeof(List));
  if(temp != NULL)
    {
      curr = node;
      temp->str=string_dup(content);
      temp->next=curr->next;
      curr->next=temp;
      return 0;
    }
  return 1;
}

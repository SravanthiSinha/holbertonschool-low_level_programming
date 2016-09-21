#include <string.h>
#include "list.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int add_end_cl_list(List **list, char *str)
{
  List *node;
  List *temp;
  List *head;
  
  node = *list;
  head = *list;
  
  if(node != NULL)
    while(node->next!=head)
      node = node->next;
  
  temp = malloc(sizeof(List));
  if(temp != NULL)
    {
      temp->str = strdup(str);
      if (node != NULL)
	{
	  temp->next = head;
	  node->next = temp;
	}
      else
	{
	  *list = temp;
	   temp->next = *list;
	}
      return 0;
    }        
  return 1;
}

int add_begin_cl_list(List **list, char *str)
{

  List *temp;
  List *head;
  List *node;
  head = *list;
  node = *list;
  temp = malloc(sizeof(List));

  if(node != NULL)
    while(node->next!=head)
      node = node->next;

    if(temp != NULL)
      {
	temp->str = strdup(str);
	if (head!= NULL)
	  {
	    temp->next = head;
	    node->next = temp;
	    *list = temp;
	  }
	else
	  {
	  *list = temp;
	  temp->next= *list;
	  }
	return 0;
      }
    
  return 1;  
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

int add_list_node(List **list,char *data)
{
  List *temp;
  temp = malloc(sizeof(List));
  if(temp)
    {
      temp->node = malloc(sizeof(NTree));
      if(temp->node)
	{
	  temp->node->str = strdup(data);
	  if(*list)
	    temp->next = *list;
	  else
	      temp->next = NULL;
	  *list = temp;
	  return 0;
	}
    }
  return 1;
}

int ntree_insert(NTree **tree, char **parents, char *data)
{
  NTree *node;
  int i;
  node = *tree;
  if(*tree == NULL)
    {
      *tree = malloc(sizeof(NTree));
      (*tree)->str = strdup(data);
      (*tree)->children = NULL;
      return 0;
    }
  else
    {
      for(i = 0;parents[i+1];i++);
      if(strcmp(parents[i],node->str) == 0)
	return add_list_node(&(node->children),data);
      while(node)
	{
	  if(strcmp(parents[i],node->str) == 0)
	    return ntree_insert(&node,parents,data);
	  else
	    node = node->children->node;
	}
    }
  return 1;
}


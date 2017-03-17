#include <stdlib.h>
#include <string.h>
#include "tree.h"

int ntree_insert(NTree **tree, char **parents, char *data);
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
	  temp->node->children = NULL;
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

NTree *findnode(NTree *tree,char **parents)
{
  List *list;
  int i;
  for(i = 1;parents[i];i++)
    {
      list = tree->children;
      while(strcmp(parents[i],list->node->str) != 0)
	list = list->next; 
      tree = list->node;
    }
  return tree;
}
int ntree_insert(NTree **tree, char **parents, char *data)
{
  NTree *node;
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
      node = findnode(*tree,parents);
      return add_list_node(&(node->children),data);
    }
  return 1;
}


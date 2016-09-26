#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>

int btree_insert(BTree **tree, char *data)
{
  if(*tree == NULL)
    {
      *tree = malloc(sizeof(BTree));
      if(*tree != NULL)
	{
	  (*tree)->str = strdup(data);
	  (*tree)->left = NULL;
	  (*tree)->right = NULL;
	  return 0;
	}
      return 1;
    }
  else if(strcmp(data,(*tree)->str) >= 0)
    return btree_insert(&(*tree)->right,data);
  else if(strcmp(data,(*tree)->str) < 0)
   return  btree_insert(&(*tree)->left,data);
  
  return 1;
}

#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>

void print_btree(BTree *tree); 
BTree *btree_find(BTree *tree, char *data)
{
  if(tree != NULL)
    {
      if(strcmp(data,tree->str) == 0)
	  return tree;
      else if(strcmp(data,tree->str) > 0)
	return btree_find(tree->right,data);
      else if(strcmp(data,tree->str) < 0)
	return btree_find(tree->left,data);
    }
  else
    return NULL;
}

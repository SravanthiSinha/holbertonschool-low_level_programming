#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include <stdio.h>


int btree_depth(BTree *tree)
{
  int lD;
  int rD;
  
  lD = 0;
  rD = 0;
  if(tree)
    {
      lD = btree_depth(tree->right);
      rD= btree_depth(tree->left);
      if(lD>rD)
	return lD+1;
      else
	return rD+1;
    }
  else
    return -1;
}


#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
BTree *btree_find(BTree *tree, char *str);
BTree *array_to_btree(char **array);
void print_btree(BTree *tree);
void btree_free(BTree *tree);
int btree_depth(BTree *tree);

int main(void)
{
  BTree *btree;
  BTree *ftree;
  
  char *a[] = {"98","40","256", NULL};
  if(!(btree = array_to_btree(a)))
     return (1);
  print_btree(btree);
  //ftree = btree_find(btree,a[1]);
  //print_btree(ftree);
  printf("Depth of tree :%d\n",btree_depth(btree));
  btree_free(btree);
  
  return (0);  
}

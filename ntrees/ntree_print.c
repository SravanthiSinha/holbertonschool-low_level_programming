#include <stdlib.h>
#include <string.h>
#include "tree.h"

int print_char(char c);
void print_ntree(NTree *tree,int tabindex);

void print_string(char *s)
{
  int i;
  i = 0;
  while(s[i])
    {
    print_char(s[i]);
    i++;
    }
  print_char('\n');
  return;
}

void ntree_print(NTree *tree)
{
  NTree *node;
  node = tree;

  if (node)
    print_ntree(node,0);
  return;
}

void print_ntree(NTree *ntree,int tabindex)
{
  NTree *node;
  int i;
  node = ntree;
  i = 0;
  if(node != NULL)
    {
      while(i < tabindex)
	{
	  print_char('\t');
	  i++;
	}
      print_string(node->str);
      while(node->children)
	{
	  print_ntree(node->children->node,tabindex+1);
	  node->children = node->children->next;	  
	}
    }
  return ;
}


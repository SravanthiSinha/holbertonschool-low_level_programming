#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int node_cmp(List *, List *);
void print_list(List *);
int size_ll(List **a)
{
  int i;
  List *node;

  node = *a;
  i = 0;

  while(node)
    {
        i++;
      node = node->next;
    }

  return i;  
}

void str_swap(char **a,char **b)
{
  char *c;
  
  c = *a;
  *a = *b;
  *b = c;

}

List *getNode(List **a,int n)
{
  int i;
  List *node;

  node = *a;
  i = 0;
  
  while(i<n)
    {
      node = node->next;
      i++;
    }
  return node;
}

List *getCNode(List **a,int n)
{
  int i;
  List *node;
  List *temp;
  
  node = *a;
  i = 0;
  
  while(i<n)
    {
      node = node->next;
      i++;
    }
  temp = malloc(sizeof(List));
  temp->str = strdup(node->str);
  temp->next = NULL;
  return temp;
}


void quick_sort(List **a,int s,int n,int (*cmp)(List *, List *))
{
    int i;
    int j;
    int mid;
    List *pivot;

    if (n < 2)
      return ;
    mid = n /2;
    pivot = getCNode(a,mid);

    for(i = 0, j = n - 1;i < j;)
      {
	if(cmp(pivot,getNode(a,i+s)) > 0)
	  i++;
	if(cmp(pivot,getNode(a,j+s)) < 0)
	    j--;
	str_swap(&(getNode(a,i+s)->str),&(getNode(a,j+s)->str));
      }
    free(pivot->str);
    free(pivot);
    quick_sort(a,s,i,cmp);
    quick_sort(a,i+1, n - i -1,cmp);
}

void sort_list(List **a, int (*func)(List *a, List *b))
{
  int n ;
  n = size_ll(a);
  quick_sort(a,0,n,func);
}


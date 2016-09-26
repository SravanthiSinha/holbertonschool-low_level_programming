#include <string.h>
#include <stdio.h>

void print_array_str(char **);
int size_array(char **a)
{
  int i;

  i = 0;

  while(a[i])
    i++;

  return i;  
}

void str_swap(char **a,char **b)
{
  char *c;

  c = *a;
  *a = *b;
  *b = c;
}

void quick_sort(char **a,int s,int n)
{
  int i;
  int j;
  int mid;
  char *pivot;

  if (n < 2)
    return ;
  mid = n /2;
  pivot = a[mid];
  for(i = 0, j = n - 1;i < j;)
    {
      if(strcmp(pivot,a[i+s])> 0)
	i++;
      if(strcmp(pivot,a[j+s]) < 0)
	j--;
      str_swap(&a[i+s],&a[j+s]);
    }
}

void sort_str_array(char **a)
{
  int n ;

  n = size_array(a);
  quick_sort(a,0,n);
}


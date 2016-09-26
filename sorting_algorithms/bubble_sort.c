#include <stdio.h>

void swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;  
}

void bubble_sort(int *a, int n)
{
  int i;
  int j;

  for(i = n - 1; i > 0; i--)
    {
      for(j = 0;j < i; j++)
	{
	  if(a[j] > a[j + 1])
	    swap(&a[j],&a[j+1]);
	}
    }
}

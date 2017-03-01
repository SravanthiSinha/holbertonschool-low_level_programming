#include <stdlib.h>

void print_array(int *a,int n)
{
  int i;
  i = 0;
  while(i<n)
  {
    if(i == 0)
      printf("%d",a[i]);
    else
      printf(",%d",a[i]);
    i++;
  }
  printf("\n");
}

void merge(int *a,int n,int mid)
{
  int left,leftend,right,i;
  int *x ;
  left = 0;
  leftend = mid -1;
  right = n-1;
  
  x = malloc(sizeof(int)*n);
  i = 0;
  while(left <= leftend && mid <= right)
    {
      if(a[left] < a[mid])
	x[i++] = a[left++];
      else
	x[i++] = a[mid++];
    }
  while(left <= leftend)
    x[i++] = a[left++];
  while(mid <= right)
    x[i++] = a[mid++];
  
  for (i = 0; i < n; i++) {
    a[i] = x[i];
  }
  free(x);
}
void merge_sort(int *a, int n)
{
  int mid;
  if(n < 2)
    return;
  else
    {
      mid = n /2;
      merge_sort(a, mid);
      merge_sort(a + mid, n-mid);
      merge(a,n,mid);
    }
}

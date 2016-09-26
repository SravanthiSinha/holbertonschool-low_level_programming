/*function that swaps 2 ints by ref*/
void swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}

/* function that sort an array 
on integers in ascending order*/
void quick_sort(int *a,int n)
{
  int i;
  int j;
  int mid;
  int pivot;

  if(n < 2)
    return;
  
  mid = n/2;
  pivot =a[mid];

  for(i = 0,j = n - 1;i < j;)
    {
      if(a[i] < pivot)
	  i++;
      if(a[j] > pivot)
	  j--;
      swap(&a[i],&a[j]);
    }
    quick_sort(a,i);
    quick_sort(&a[i+1],n-i-1);
}


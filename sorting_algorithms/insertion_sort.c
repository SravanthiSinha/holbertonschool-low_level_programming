void swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}

void insertion_sort(int *a, int n)
{
  int i;
  int j;

  for(i = 0; i < n; i++)
    {
      for(j = i; j > 0;j--)
	{
	  if(a[j]<a[j-1])
	    {
	      swap(&a[j],&a[j-1]);
	    }
	}
    }
}

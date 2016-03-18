/* The function reverse_array
 * reverses the content of an array of integers.
 * It takes a argument (int *,int) and
 * returns no arguments (void)
 */


void reverse_array(int *a, int n)
{
  int i,j,c;
  
  for(i=0,j=n-1;i< n/2  && j>=0;i++,j--)
    {
      c=a[i];
      a[i]=a[j];
      a[j]=c;
    }
}


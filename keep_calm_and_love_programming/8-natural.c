#include <stdio.h>

/* The function  prints
 *prints the sum of all the multiples of 3 or 5 below 1024 (excluded),
 * followed by a new line. 
 * It takes a argument (void) and
 * returns a int
 */
int main(void){
  int n,i;
  int sum;

  n=1024;
  sum=0;
  for(i=1;i<n;i++)
    {
      if(i%3==0 || i%5==0)
	sum=sum+i;
    }
  printf("%i\n",sum);  
  return 0;
}

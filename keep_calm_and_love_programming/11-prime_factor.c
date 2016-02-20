#include<stdio.h>

int main(void)
{
  unsigned long  n, div, max;
  
  div=2;

  n=612852475143;
  while(n!=0){
    if(n % div !=0)
      div = div + 1;
    else{
      max  = n;
      n = n / div;

      if(n == 1){
	printf("%ld\n",max);	
	break;
      }
    }
  }
  return 0;
}

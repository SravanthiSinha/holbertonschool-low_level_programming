#include<stdio.h>

/* The function prints the  prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * It takes no arguments argument (void) and
 * returns an int
 */ 
int main(void)
{
 long  count,a,b,c;
  a=0;
  b=1;
  c=0;

  for (count=0;count<50;count++)
    {
      printf("%lu",a+b);
      if(count<49) printf(", ");
      c=a;
      a=b;
      b=c+b;      
    }
   printf("\n");

  return 0;
}

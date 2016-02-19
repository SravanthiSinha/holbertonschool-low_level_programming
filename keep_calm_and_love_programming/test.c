#include<stdio.h>

int main(void)
{
 long  count,a,b,c;
  a=0;
  b=1;
  c=0;
  printf("0, 1, ");
  for (count=1;count<=98;count++)
    {
      /*      printf("%.0f",a+b);*/
      printf("%lu",a+b);
      if(count<98) printf(", ");
      c=a;
      a=b;
      b=c+b;      
    }
	 printf("\n");

  return 0;
}

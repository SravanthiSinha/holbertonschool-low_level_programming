#include<stdio.h>
#include<math.h>

long double getFib(int count)
{
  long double result;
  double g1=1.618034;
  double g2=0.618034;
  result=pow(g1,count)-pow((g2*-1),count);
  result=result/sqrt(5);
  return result;
  
}


int main(void)
{
  int count;
  printf("0, 1, ");
  for (count=1;count<=98;count++)
    {
      printf("%.0Lf", getFib(count);	    
      if(count<98) printf(", ");        
    }
	 printf("\n");

  return 0;
}

#include<stdio.h>
#include<math.h>


double power(double a, int b)  /* POWER function  */
{
  double pow = 1;
  int b1;
 
  if (b == 0)            /* case of any number raised to 0 is 1 */
    return 1.0;
 
  else
    if (a == 0.0)          /* case of 0 to any power but 0 is 0  */
      return 0.0;
 
    else                   /* do non 0 pos and neg powers and numbers  */
      {
	if (b > 0)           /* normalize the power to a positive number  */
	  b1 = b;            /* since fractions are not as accurate       */
	else
	  b1 = -1 * b;
 
	pow = a;                 /*  calculate power doing recursive call  */
	pow *= power(pow, b1-1);
 
	if (b < 0.0)          /* case of negative exponents  */
	  pow = 1.0/pow;
 
	return  pow;
      }
}

long double getFib(int count)
{
  long double result;
  double g1=1.618034f;
  double g2=0.618034f;
  printf("%f",power(g1,count));
  result=power(g1,count)-power((g2*-1),count);
  result=result/power(5,0.5);
  return result;
  
}


int main(void)
{
  int count;
  printf("0, 1, ");
  for (count=3;count<=3;count++)
    {
      printf("%lu", fib(count));	    
      if(count<98) printf(", ");        
    }
	 printf("\n");

  return 0;
}

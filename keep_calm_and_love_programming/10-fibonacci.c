#include<stdio.h>
#include<float.h>

/* This is the prototype of the function Fib (Fibonacci Number) */ 
double Fib(double);

/* The function prints the  sum of the even-valued Fibonacci Number terms
 * which are less than 4,000,000 , followed by a new line.
 * uses fucntion Fib to compute a nth Fibonacci Number
 * It takes a argument (int) and
 * returns nothing (void)
 */ 
int main(void)
{
  long  i = 1, fNo=0,sum=0;

   while (fNo<=4000000)
    {
      fNo=Fib(i);
      if(fNo%2==0)
	sum=sum+fNo;	
      i++; 
   }
   printf("%ld\n",sum);
   return 0;
}

/* The function Fib computes a Fibonacci Number recursively
 * It takes a argument (int) and
 * returns int
 */ 
double  Fib(double  n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fib(n-1) + Fib(n-2) );
} 

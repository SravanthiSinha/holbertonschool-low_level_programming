#include<stdio.h>
#include<float.h>

/* This is the prototype of the function Fib (Fibonacci Number) */ 
double Fib(double);

/* The function prints the first 98 Fibonacci numbers,
 * followed by a new line.
 * uses fucntion Fib to compute a nth Fibonacci Number
 * It takes a argument (int) and
 * returns nothing (void)
 */ 
int main(void)
{
   double  i = 0, counter;

   for ( counter = 1 ; counter <= 50 ; counter++ )
    {
      printf("%f", Fib(i));
      if(counter<98)
	{ 
	printf(", ");
	}
      i++; 
   }
   printf("\n");
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

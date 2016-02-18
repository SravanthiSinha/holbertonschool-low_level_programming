#include<stdio.h>
 
int Fib(int);
 
int main()
{
   int  i = 0, counter;

   for ( counter = 1 ; counter <= 98 ; counter++ )
    {
      printf("%d", Fib(i));
      if(counter<98)
	{ 
	printf(", ");
	}
      i++; 
   }
 
   return 0;
}
 
int Fib(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fib(n-1) + Fib(n-2) );
} 

#include<stdio.h>

/* This the main function which prints
 * prints the numbers from 1 to 100.
 * But for multiples of three print Fizz 
 * instead of the number and for the multiples of five print Buzz.
 * For numbers which are multiples of both three and five print FizzBuzz.
 * It takes no argument (void) and
 * returns nothing (void)
 */
int main (void)
{
  int i;
  for (i=1; i<=100;i++)
    {
      if (i%5==0 && i%3==0)
	printf("FizzBuzz");
      else if(i%5==0)
	printf("Buzz");
      else if(i%3==0)
	printf("Fizz");      
      else
	printf("%i",i);
      if(i<100)
	printf(" ");
    }
  return(0);
}

#include<stdio.h>

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

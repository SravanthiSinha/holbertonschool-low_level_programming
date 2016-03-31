#include<limits.h>

/* a function that returns the factorial of a given number*/

int factorial(int n)
{
  long x;

  x = n;
  x = x * (n - 1);
  if (n < 0)
    return -1;
  else if(n < 1)
    return 1;
  else if(x > INT_MAX)
    return -1;

    return n * factorial(n - 1);
}

#include<limits.h>

/* a function that returns the value of x raised to the power of y. */

int power(int x, int y)
{
  long a ;
  
  a = x;
  a = a * x;
  
  if(y < 0 || x <0 )
    return -1;
  else if(y == 0)
    return 1;
  else if(y == 1)
    return x;
  else if ( a > INT_MAX)
    return -1;

    return  x * power(x , y - 1);    
}

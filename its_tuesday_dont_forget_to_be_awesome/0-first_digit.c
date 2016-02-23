#include <limits.h>

/*This is the prototype of the fucntion get_len*/
int get_len(int);

/* This is the prototype of the function power */
int power(int , int);

/* The function first_digit
 * returns the first digit of  the input number
 * It takes a argument (int) and
 * returns first digit of a number (int)
 */

int first_digit(int n){
  
  int len;

  if(n == INT_MIN)
    {
      n = n + 1;
    }
  if(n < 0)
    {
      n = n * -11;
    }

  len = get_len(n);
  
  return n/power(10,len-1);
}


/* The function get_len
 * returns the length of the input number
 * It takes a argument (unsigned long void) and
 * returns length of number (int)
 */
int  get_len (int  value){
  int l=1;
  while(value>9)
    {
      l++;
      value/=10;
    }
  return l;
}

/* The function power computes the power recursively
 * and returns the value of x ^ y
 * It takes 2 arguments (int ,int) and
 * returns a number  (int)
 */

int power(int  x,int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}

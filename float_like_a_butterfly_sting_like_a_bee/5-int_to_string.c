#include<stdlib.h>

/* The function get_len
 * returns the length of the input number
 * It takes a argument (unsigned long void) and
 * returns length of number (int)
 */
int  get_len (long value){
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
 * It takes 2 arguments (unsigned long,int) and
 * returns a number  (long)
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

/*
 * The function returns a pointer to 
 * a newly allocated space in memory,
 * which contains a string representing
 * the number given as a parameter
 *
 */
char *int_to_string(int x)
{
  int len = 0,i = 0,j = 0,flag = 0;
  char *s;  long n = x, temp =0;  
  if ( n < 0 )
    {
      n = n * -1;
      flag = 1;
    }
  len = get_len(n);
  s = flag ? malloc(sizeof( *s ) * (len + 1)): malloc(sizeof( *s ) * len);
  if (s == NULL)
      return (NULL);
  else
    {
      if(flag)
	{
	  s[j]='-';
	  j++;
	}      
      for(i = len -1 ;i >= 0; i--, j++)
	{
	  temp = n / power(10,i);
	  s[j] = temp + 48;
	  n = n - temp * power(10 , i); 
	  }
    }
  return s; 
}

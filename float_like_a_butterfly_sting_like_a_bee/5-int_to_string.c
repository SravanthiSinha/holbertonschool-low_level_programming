#include<stdlib.h>
#include<stdio.h>
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
  int len,i,j;
  char *s;
  int flag;  
  long n, temp;

  n = x;
  flag = 0;
  j = 0;
  temp = 0;
  

  if ( n < 0 )
    {
      n = n * -1;
      flag = 1;
    }
    
  len = get_len(n);
  i = len - 1;
  
  if (flag)
    s = malloc(sizeof(*s) * (len +1));
  else
    s = malloc(sizeof(*s) * len);
  
  if (s == NULL)
    {
      return (NULL);
    }
  else
    {
      if(flag)
	{
	  s[j]='-';
	  j++;
	}
      
      while(i >= 0)
	{
	  temp = n / power(10,i);
	  s[j] = temp + 48;
	  n = n - temp * power(10 , i); 
	  i--;
	  j++;
	  }
    }
  return s; 
}

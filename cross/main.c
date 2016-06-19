#include "headers.h"

/* A utility function to check whether x is numeric*/
bool isNumericChar(char x)
{
  return (x >= '0' && x <= '9')? true: false;
}
  
/* A simple atoi() function. If the given string contains
 * any invalid character, then this function returns 0 */
int atoi(char *str)
{
  int res;
  int sign;
  int i;

  res = 0;
  sign = 1;
  i = 0;
  if (str[0] == '-')
    {
      sign = -1;
      i++; 
    }
  for (; str[i] != '\0'; ++i)
    {
      if (isNumericChar(str[i]) == false)
	return 0; 
      res = res*10 + str[i] - '0';
    }
  return sign*res;
}

void print_cross(int n)
{
  int i;
  int j;
  int odd;
  
  odd = n%2;
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  if(i == n/2 && j == n/2 && odd)
	    {
	      print_char('X');
	      for (;j < n-1;j++)
		print_char(' ');
	      break;
	    }
	  if(i == j)
	    print_char('\\');
	  if(j==(n-i-1) )
	    print_char('/');
	  else if (i-j)
	    print_char(' ');	  	  
	}
      print_char('\n');
    }
}

int main (int argc, char*argv[])
{
  int n;

  n = 0;
  if (argc !=2)
    return 1;
  else
    n = atoi(argv[1]);
  
  if(n > 0)
    { 
      print_cross(n);
    }
    
  return 0;
}

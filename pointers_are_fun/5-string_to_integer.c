#include<limits.h>
#include<stdio.h>
int is_number(char s)
{
  int i;
  i = 10;
  if(s >= 48 && s <= 57)
    i = s - 48;
  if(s == 45)
    i = s;
  return i;
  
}
int string_to_integer(char *s){
  int i;
  int no;
  int n;
  int sign;
  no = 0;

  for (i = 0,  no = 0, sign = 0;s[i]!='\0';i++)
    {
      n = is_number(s[i]);
      if(n == 45)
	  sign = sign +1;
      else
	{
	  if (( no == (INT_MAX / 10) && n >= 8) && sign%2 == 0)
	    return (0);
	  else if (no > (INT_MAX / 10) || no > (INT_MAX))
	    return (0);
	  else if(n < 10)
	    {
	      no = 10*no + n;
	    }
	}
      if(n<10 && is_number(s[i+1])>=10)
	   break;
    }
  if(sign%2 == 0)
    return no;
  else
    return -1*no;
}

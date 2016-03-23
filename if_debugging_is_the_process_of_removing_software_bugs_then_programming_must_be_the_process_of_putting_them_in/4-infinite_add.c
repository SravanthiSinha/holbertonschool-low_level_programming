#include<stdio.h>
int str_len(char *str)
{
  int len;

  len=0;
  while(*(str+len)!='\0')
    len++;
  return len;
}

/* The function reverse_string takes
 * an pointer to char
 * and prints the string in reverse.
 * It takes a argument (char *) and
 * returns nothing (void)
 */


void reverse_string(char *s)
{
  int len,i;
  char p[1000];

  i=0;
  len=str_len(s) - 1;
  
  while(len >= 0)
    {
      *(p + i) = *(s + len);
      len--;
      i++;
    }

  *(p + i)='\0';
  i=0;
  while(*(p + i) != '\0')
    {
      *( s + i ) = *(p + i);
      i++;
    }
}
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
  int a,b,i,j,carry,sum,max,c;
  
  a=str_len(n1);
  b=str_len(n2);
  carry=0;
  c=0;
  

  max = (a > b) ? a : b;
  if(size_r-1>max)
    {
      for(i = a-1, j = b-1 ; i >= 0 || j >= 0; i--, j--, c++)
	{
	 if(i>=0 && j>=0)
	   sum = (char) ( (int) n1[i] + (int) n2[j] + carry - 96);
	 else if(j<0)
	   {	     
	   sum = (char) ( (int) n1[i] + carry - 48);
	   }
	 else if(i<0)
	   {	     
	   sum = (char) ( (int) n2[j] + carry - 48);
	   }
	  if(sum >= 10)
	    {
	      carry = sum/10;
	      sum = sum%10;
	    }
	  else 
	    {
	      carry=0;
	    }	  
	  r[c] =(char) (sum+48);
	}	 

        if(carry>0) 
	  r[c]=(char) (carry+48);
      reverse_string(r);
    }
  else
    {
      return 0;
    }


  return r;
}

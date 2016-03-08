#include<stdio.h>
/* The function power computes the power recursively
 * and returns the value of x ^ y
 * It takes 2 arguments (unsigned long,int) and
 * returns a number  (long)
 */

long power(int x,int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}

int reversenumber(int n, int len)
{
  int tmp,x;

  while(len>0)
    {
      tmp=n%10;
      x=x+tmp*power(10,len-1);
      n=n/10;
      len--;      
    }

  return x;
  
}

int getlength(char *s)
{
  int x,i,len;
  
  x=0;
  i=0;
  len=0;
  while (*(s+i)!='\0')
    {
      x= (*(s+i)-48);
      if(x>=0 &&  x <=9)
	{
	  len++;
	  if(*(s+i+1)<47  || *(s+i+1)>57)
	    break;
	}
      i++;
    }
  return len;
}

int getsign(char *s)
{
  int x,i,len;
  
  x=0;
  i=0;
  len=0;
  while (*(s+i)!='\0')
    {
      x= (*(s+i));
      if(x=='-')
	{
	  len++;
	  if(*(s+i+1)<47  || *(s+i+1)>57)
	    break;
	}
      if(x=='+')
	{
	  len--;
	  if(*(s+i+1)<47  || *(s+i+1)>57)
	    break;
	}
      
      i++;
    }
  return len;
}

int string_to_integer(char *s)
{
  int i,p,x,neg,len,op;
  long n;
  n=0,i=0, p=0,neg=0;
 
  len=getlength(s);
  p=len;
  neg=getsign(s);
  while(*(s+i)!='\0')
    {
      x=(*(s+i) -48) ;      
     
      if(x>=0 && x<=9 )
	{	  
	  n= n + power(10,p-1)*x;
	  
	   if(n>2147483647 && neg==0)
	    {
	      n=0;
	      break;
	    }
	   if(*(s+i+1)<47  || *(s+i+1)>57)
	    {	      
	    break;
	    }
	   p--;
        }
      i++;
    }
  
    if(neg==1)
      op=-1*n;
    else
      op=n;
  return op;
}

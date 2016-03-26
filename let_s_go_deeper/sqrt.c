int checklastno(int n)
{
  if ( n%10 == 2 || n%10 == 3  || n%7 == 7)
    return 1;
  else
    return 0;
}

int issqrt(unsigned long  n, int d,unsigned long o)
{

  if( n*n != o)
    return issqrt( n/d, d , o );
  else if( n*n == o)
    return n;
  return -1;
}

int square_root(int n)
{
  
  int d;
  
   d = 0;
  
  if(n <= 0)
    return -1;
  else if( n == 1)
    return 1;
  else if (checklastno(n))
    return -1;
  else
    {
      if( n % 2 == 0)
	d = 2;
      else if(n % 3 == 0)
	d = 3;
      else if(n % 5 == 0)
	d = 5;
      else if(n % 7 == 0)
	d=7;      
      if( d == 0)
	return -1;      
      return issqrt((unsigned long)n,d,(unsigned long)n);
    }

}

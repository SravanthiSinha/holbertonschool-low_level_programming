int primalitytest(int n, int d)
{
  if (n<=1)
    return 0;
  else if( d > n/2)
    return 1;
  else if ( n % d == 0)
    return 0;
    return primalitytest(n,d+1);     
}


int is_prime_number(int n)
{
  return primalitytest(n,2);
}

int primalitytest(int n, int d)
{
  if (n <= 1)
    return 0;
  else if( d > n / 2)
    return 1;
  else if ( n % d == 0)
    return 0;
    return primalitytest(n , d+1);     
}

/*a function that returns 1 if a number is a prime number, 0 otherwise.*/
int is_prime_number(int n)
{
  return primalitytest(n, 2);
}

int findsqrt(int n ,int count)
{
  if ( count*count == n) return count;
  if ( count *count > n) return -1;
  return findsqrt(n,count+1);
  return 0;
}

int square_root(int n)
{
 return   findsqrt(n,1);
}

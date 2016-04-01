/*a function that returns the natural square root of a number*/

int findsqrt(int n ,int count)
{
  if( count * count == n)
    return count;
  if( count * count > n)
    return -1;
  
  return findsqrt(n,count+1);
  
}

int square_root(int n)
{
  return   findsqrt(n,1);
}

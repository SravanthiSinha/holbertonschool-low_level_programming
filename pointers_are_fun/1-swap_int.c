/* The function swap_int takes 
 * values of two integers and swaps it.
 * It takes 2 arguments (int *, int *) and
 * returns nothing (void)
 */

void swap_int(int *a,int *b)
{
  int c;

  c=*a;
  *a=*b;
  *b=c;
}

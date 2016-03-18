int print_char(char);

/* The function print_line of length n
 * draws a straight line on the terminal
 * It takes a argument (int) and
 * returns nothing (void)
 */

void print_line(int n)
{
  int i;

  if(n>0)
    {
      for(i=0;i<n;i++)
	print_char('_');	
    }
  print_char('\n');
  
}

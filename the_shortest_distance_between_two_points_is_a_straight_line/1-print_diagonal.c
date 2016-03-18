int print_char(char);

/* The function print_diagonal
 * draws a diagonal line 
 * of length n on the terminal
 * It takes a argument (int) and
 * returns nothing (void)
 */

void print_diagonal(int n)
{
  int i,j;

  if(n>0)
    {
      for(i=0;i<n;i++)
	{
	  for(j=0;j<i;j++)	    
	    {
	      print_char(' ');
	    }	
	print_char('\\');	
	print_char('\n');
	}
    }  
  if (n<=0)
    print_char('\n');
}

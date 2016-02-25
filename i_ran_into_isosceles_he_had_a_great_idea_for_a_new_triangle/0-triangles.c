#include<unistd.h>

int print_char(char c)
{
  return (write (1, &c, 1));
}
/* The function triangles_in_the_term prints
 *  n triangles of height h.
 * It takes 2 argument (int , int) and
 * returns nothing (void)
 */

void triangles_in_the_term(int h, int n)
{
  int i,j,no,br;

  if( n > 0  &&  h > 0)
    {
      for( no = 0; no < n; no++ )
	{
	  br = 0;
	  for(i = 0; i < h; i++)
	  {	   
	    for(j = 0; j < (2 * h) - 1; j++)
	    {	     
	      if (j >= h - 1 - br && j <= h - 1 + br )
		{
		  print_char('*');
		}
	      else if(j < h - 1 - br) {
		print_char(' ');
	      }	 	      	     
	    }
	    br++;
	  print_char('\n');
	  }
	}
    }    
}

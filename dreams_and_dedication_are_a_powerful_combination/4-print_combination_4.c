#include "my_functions.h"

/* The function print_combination_4 takes no arguments
 * and prints - all possible combinations of two two-digit numbers
 * seperated by comma followe by a space. 
 * takes no argument
 * returns nothing (void)
 */

void print_combination_4(void){
  int i,j, k,l,a,b;
  int end=9;
  
  for(i=0;i<=end;i++)
      for (j=0;j<=end;j++)	
	  for (k=0;k<=end;k++)	    
	      for (l=0;l<=end;l++)
		{
		  a=i*10+j;
		  b=k*10+l;
		  if((a<b) )
		    {
		      print_number(i);
		      print_number(j);
		      print_char(' ');
		      print_number(k);
		      print_number(l);
		      if(  a!=98 ) 
			{
			  print_char(',');
			  print_char(' ');
			}
		    }
		}
}       

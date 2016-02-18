#include<stdio.h>

/* The function print_to_98 takes a number and
 * prints - on one line - all numbers from its value to 98,
 * followed by a new line. 
 * It takes a argument (int) and
 * returns nothing (void)
 */

void print_to_98(int n){
  int i;

  if(n<98)
  for(i=n;i<=98;i++)
    {
    printf("%d",i);
    if(i<98)printf(", ");
    if(i==98)printf("\n");
    }
  else
 for(i=n;i>=98;i--)
    {
    printf("%d",i);
    if(i>98)printf(", ");
    if(i==98)printf("\n");
    }

}

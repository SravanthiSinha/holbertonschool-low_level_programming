#include "my_functions.h"

int absolute(int n){
  if(n<0) return -n;
  else return n;
}

/* The function print_last_digit prints
 * the last digit of an integer
 * It takes a argument (int) and
 * returns nothing (void)
 */
void print_last_digit(int n)
{
  print_char(absolute(n%10) +48);
}


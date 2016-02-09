#include "my_functions.h"

/* The function print_alphabet prints
 * the values from a to z.
 * It takes no argument (void) and
 * returns nothing (void)
 */
void print_alphabet(void)
{
  char c;
  for(c='a';c<='z';++c)
    print_char(c);  
}

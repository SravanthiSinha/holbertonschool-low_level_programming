int print_char(char);

/* The function print_string takes 
 * an pointer to a char
 * and prints a string.
 * It takes a argument (char *) and
 * returns nothing (void)
 */

void print_string(char *str)
{
  int i=0;
  
  while(*(str+i)!='\0')
    {
      print_char(*(str+i));
      i++;
    }
}

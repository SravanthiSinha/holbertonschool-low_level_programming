int print_char(char);

/* The function print_string2  prints
 * only one character out of two, 
 * starting with the first one
 * It takes a argument (char *) and
 * returns nothing (void)
 */

void print_string_2(char *str)
{
  int i;
  i=0;

  while(*(str+i)!='\0')
    {
      if(i%2==0)
	{
	print_char(*(str+i));
	}
      i++;
    }
}

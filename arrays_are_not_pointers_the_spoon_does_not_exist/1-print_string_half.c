int print_char(char c);

/* The function str_len takes a string
 * and returns the length of string
 * It takes a argument (char *) and
 * returns an argumenet (int)
 */

int str_len(char *str)
{
  int len=0;

  while(*(str+len)!='\0')
    {
      len++;
    }

  return len;
}


/* The function print_string_half prints
 * half of a string.
 * It takes a argument (char *) and
 * returns nothing (void)
 */

void print_string_half(char *str)
{
  int len,i;
  
  len = ( str_len( str ) + 1 ) / 2;
   
  for(i = 0; i < len; i++)
    print_char(*(str+len+i));
  
}

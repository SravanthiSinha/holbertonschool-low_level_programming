int str_len(char *str)
{
  int len;

  len=0;
  while(*(str+len)!='\0')
    len++;
  return len;
}

/* The function reverse_string takes
 * an pointer to char
 * and prints the string in reverse.
 * It takes a argument (char *) and
 * returns nothing (void)
 */


void reverse_string(char *s)
{
  int len,i;
  char p[1000];

  i=0;
  len=str_len(s) - 1;
  
   while(len >= 0)
    {
      *(p + i) = *(s + len);
      len--;
      i++;
    }

    *(p + i)='\0';
    i=0;
   while(*(p + i) != '\0')
      {
        *( s + i ) = *(p + i);
        i++;
      }
}

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
  int len,i,j;
  char c;

  len=str_len(s);
 
  for (i = 0, j = len -1; i < ((len -1 ) /2);i++,j--)
    {
      c = *(s + i);
      *(s + i)= *(s +j);
      *(s + j)= c;
    }
}

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



void print_string_half(char *str)
{
  int len,start;
  
  len=str_len(str);
   
  if(len%2==0)
    start=len/2;
  else
    start= (len/2)+1;
  while(*(str+start)!='\0')
    {
      print_char(*(str+start));
      start++;
    }
  
}

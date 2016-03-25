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

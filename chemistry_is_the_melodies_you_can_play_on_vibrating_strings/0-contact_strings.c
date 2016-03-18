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

/* The function concat_strings 
 * concatenates two strings.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */


char *concat_strings(char * dest,const char *src)
{
  int i,n;

  i=0;
  n=str_len(dest);

    while(*(src+i)!='\0')
      {
	*(dest+i+n)=*(src+i);
	i++;
      }
    return dest  ;
}

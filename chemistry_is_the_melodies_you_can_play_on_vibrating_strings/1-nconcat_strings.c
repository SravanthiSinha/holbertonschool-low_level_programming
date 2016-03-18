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

char *nconcat_strings(char * dest,const char *src,int n)
{
  int i,l;

  i=0;
  l=str_len(dest);

  while((*(src+i)!='\0') && i<n)
      {
	*(dest+i+l)=*(src+i);
	i++;
      }
    return dest  ;
}

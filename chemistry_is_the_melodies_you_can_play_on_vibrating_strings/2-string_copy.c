/* The function string_copy
 * copies a string.
 * It takes a argument (char *,const char *) and
 * returns an argumenet (char *)
 */

char *string_copy(char * dest,const char *src)
{
  int i;

  i=0;
  while((*(src+i)!='\0'))
      {
	*(dest+i)=*(src+i);
	i++;
      }
    return dest  ;
}

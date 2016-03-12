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

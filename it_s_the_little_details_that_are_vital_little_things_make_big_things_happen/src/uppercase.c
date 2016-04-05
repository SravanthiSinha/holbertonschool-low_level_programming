char *uppercase(char *s)
{
  int i;
  
  i=0;
  
  while(s[i]!='\0')
    {
      if((int)s[i]>=97 && (int)s[i]<=122)
	s[i]=s[i]-32;

      i++;
    }
  return s;
}

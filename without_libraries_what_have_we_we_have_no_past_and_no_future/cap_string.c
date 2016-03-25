char *cap_string(char *s)
{
  int i;
  
  i=0;
  
  while(s[i]!='\0')
    {
      if((int)s[i]>=97 && (int)s[i]<=122)
	{
	  if( ( (int)s[i-1]==9 || (int) s[i-1]==10 || s[i-1]==32 ) && i>0)
	    s[i]=s[i]-32;
	  else if(i==0)
	    s[i]=s[i]-32;  
	}
      i++;
    }
  return s;
}

char *rot13(char *s)
{
  int i,a;
  
  i=0;
  while(s[i]!='\0')
    {
      a = (int)s[i];
      if ((a>=97 && a<110) || (a>=65 && a<78)) 
	{
	s[i]= (char)(a+13);
	}
      else if((a>=110 && a<123) || (a>78 && a<91))
	  {
	s[i]= (char)(a-13);
	  }
       i++;
    } 
  return s;
}

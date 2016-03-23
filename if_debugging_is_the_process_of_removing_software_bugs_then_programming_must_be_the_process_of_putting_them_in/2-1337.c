char *leet(char *s)
{
  int i;
  
  i=0;
  while(s[i]!='\n')
    {
      switch(s[i]){
      case 'a':
      case 'A':
	s[i]='4';
	break;
      case 'E':
      case 'e':
	s[i]='3';
	break;
      case 'o':
      case 'O':
	s[i]='0';
	break;
      case 't':
      case 'T':
	s[i]='7';
	break;
      case 'L':
      case 'l':
	s[i]='1';	
	break;
      }
      i++;
    } 
  return s;
}

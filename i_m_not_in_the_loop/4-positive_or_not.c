int print_char(char);

void positive_or_not(int a)
{
  if(a>0) print_char('P');
  else if(a<0) print_char('N');
  else if(a==0) print_char('Z');
}

int print_char(char);

void print_line(int n)
{
  int i;

  if(n>0)
    {
      for(i=0;i<n;i++)
	print_char('_');	
    }
  print_char('\n');
  
}
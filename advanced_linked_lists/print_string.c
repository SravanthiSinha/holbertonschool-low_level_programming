int print_char(char s);

void print_string(char *s)
{
  int i;

  i = 0;
  while(s[i])
    {
    print_char(s[i]);
    i++;
    }
}

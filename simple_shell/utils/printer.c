#include <unistd.h>

void print_prompt(char *s);
void print_number(int);
int print_char(char);


void print_number(int n)
{
  if ( n > 10 )
    print_number(n /10);
  print_char(n % 10 +48);  
}

int print_char(char c)
{
  write(1,&c,1);
}

void print_prompt(char *s)
{
  write(1,s,str_len(s));
}

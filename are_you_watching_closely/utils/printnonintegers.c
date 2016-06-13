#include "printf.h"
#include "strings.h"

int print_character(char c)
/* prints a character*/
{
  return write(1,&c,1);
}

int print_string(char *s){
  /* prints a string */
  return write(1,s,str_len(s));
}

int print_pointeraddress(int *p)
{
  unsigned int *x = (unsigned int *)(&p);
  int divide = sizeof(void *)/sizeof (unsigned int);
  write(1,"0x",2);
  for (divide--; divide >= 0 ; divide--) {
    print_unsigned_hexdecimal_integer(*(x+divide));
   }
  return 1;
}



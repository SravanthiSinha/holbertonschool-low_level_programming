#define BUFFER_SIZE 255
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils.h"
#include "../libshell/libshell.h"
#include <stdio.h>
void print_prompt(char *s);
void print_number(int);
int print_char(char);
int print_proccontent(char *path);

int print_proccontent(char *path)
{
  int fd;
  char buffer[BUFFER_SIZE];
  int ret_in,ret_out;

  print_prompt(path);
  fd = open(path,O_RDONLY);

  while( (ret_in = read(fd, &buffer, BUFFER_SIZE)) >0)
    {
      ret_out = write(1, &buffer,(ssize_t)ret_in);
      if(ret_out != ret_in)
	return (1); 
    }
  
  close(fd);
  return(0);
}

void print_number(int n)
{
  if ( n > 10 )
    print_number(n /10);
  print_char(n % 10 +48);  
}

int print_char(char c)
{
 return  write(1,&c,1);
}

void print_prompt(char *s)
{
  write(1,s,str_len(s));
}

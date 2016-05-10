#define BUFFER_SIZE 255
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int print_char(char);

/* The function print_string takes 
 * an pointer to a char
 * and prints a string.
 * It takes a argument (char *) and
 * returns nothing (void)
 */

void print_string(char *str)
{
  int i=0;
  
 while(*(str+i)!='\0')
    {
      print_char(*(str+i));
      i++;
    }
}

int main(int argc, char **argv)
{

  int fd;
  char buffer[BUFFER_SIZE];
  int ret_in, ret_out; 
  struct stat fileStat;
  char *cat = "cat: ";
  char *dir = ": Is a directory";
  char *ndir=" No such file or directory";

  if(argc == 1)
    {
      while((ret_in = read(0,&buffer,BUFFER_SIZE)) > 0)
	{
	  ret_out = write(1, &buffer,(ssize_t)ret_in);	  
	}
      	  if((ssize_t)ret_in == 0) 
	    return (0);
    }
  else if(argc >= 2)
    {
      if(lstat(argv[1],&fileStat) >= 0)
	{      
	  if(S_ISREG(fileStat.st_mode))
	    {      
	      fd = open(argv[1],O_RDONLY);
	      while( (ret_in = read(fd, &buffer, BUFFER_SIZE)) >0)
		{
		  ret_out = write(1, &buffer,(ssize_t)ret_in);
		  if(ret_out != ret_in)
		    return (1);	 
		}
	      close(fd);
	    }
	  else if(S_ISDIR(fileStat.st_mode) || S_ISLNK(fileStat.st_mode))
	    {
	      print_string(cat);
	      print_string(argv[1]);
	      print_string(dir);
	      print_char('\n');
	    }
	}
      else
	{
	  print_string(cat);
	  print_string(argv[1]);
	  print_string(ndir);
	  print_char('\n');  
	  return (0);
	}
      return(0);
    }
  return (1);
}

#define BUFFER_SIZE 255
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{

  int fd;
  char buffer[BUFFER_SIZE];
  int ret_in, ret_out; 
  
  if(argc != 2)
    return (1);
  else
    {
      fd = open(argv[1],O_RDONLY);
      while( (ret_in = read(fd, &buffer, BUFFER_SIZE)) >0)
	{
	 ret_out = write(1, &buffer,(ssize_t)ret_in);
	 
	 if(ret_out != ret_in)
	   return (1);	 
	}

      close(fd);
      return(0);
    }

}

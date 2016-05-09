#define BUFFER_SIZE 255
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{

  int input_fd;
  int output_fd;
  char buffer[BUFFER_SIZE];
  int ret_in, ret_out; 
  
  if(argc != 3)
    return (1);
  else
    {
      input_fd = open(argv[1],O_RDONLY);
      if (input_fd == -1) {
	return (1);
      }

      output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
      if(output_fd == -1){
        return (1);
      }

      while( (ret_in = read(input_fd, &buffer, BUFFER_SIZE)) >0)
	{
	 ret_out = write(output_fd, &buffer,(ssize_t)ret_in);
	 
	 if(ret_out != ret_in)
	   return (1);	 
	}

      close(input_fd);
      close(output_fd);
      return(0);
    }

}

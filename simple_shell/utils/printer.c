#include <fcntl.h>
#include "utils.h"
#include "../libshell/libshell.h"

int print_proccontent(char *path)
/* prints the conents of process environ of a particular id*/
{
	int fd;
	char arg_list[10024];
	size_t length;
	char* next_arg;
	fd = open(path,O_RDONLY);
	/* Read the contents of the file. */
	fd = open (path, O_RDONLY);
	length = read (fd, arg_list, sizeof (arg_list));
	close (fd);
	/* read does not NUL-terminate the buffer, so do it here. */
	arg_list[length] = '\0';
	/* Loop over arguments. Arguments are separated by NULs. */
	next_arg = arg_list;
	while (next_arg < (arg_list + length)) {
		/* Print the argument. Each is NUL-terminated,
		so just treat it like an ordinary string. */
		print_prompt (next_arg);
		print_prompt("\n");
		/* Advance to the next argument. Since each argument is
		NUL-terminated, strlen counts the length of 
		the next argument, not the entire argument list. */
		next_arg += str_len(next_arg) + 1;
	}
	return(0);
}

void print_number(int n)
/* function to write an int to the dispaly*/
{
	if (n > 10)
		print_number(n /10);
	print_char(n % 10 +48);
}

int print_char(char c)
/* function to write a character to the dispaly*/
{
	return write(1,&c,1);
}

void print_prompt(char *s)
/*function to print a string to the display*/
{
	write(1,s,str_len(s));
}

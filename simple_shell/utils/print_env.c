#include "utils.h"

void print_env(int pid)
/*fcuntion to fetch the path of the process pid and print the env*/
{
	char *path;
	char str[100];
	char *pathproc;
	int_str(pid,str);
	pathproc = string_concat("/proc/",str);
	path = string_concat(pathproc,"/environ");
	print_proccontent(path);
	free(pathproc);
	free(path);
}

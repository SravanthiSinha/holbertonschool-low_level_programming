#include "utils.h"
#include <stdlib.h>

void print_env(int pid)
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

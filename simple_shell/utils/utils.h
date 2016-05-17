#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>

/* ------ int_str.c ------ */
typedef int bool;
#define true 1
#define false 0
char* int_str(int num, char* str);

/* ------ strings.c ------ */
char *string_concat(char * dest,char *src);
int str_len(char *s);
int str_ncomp( char *s1, char*s2, int k);
void reverse(char str[], int length);
char *string_dup(char *str);

/* ------ swap.c ------ */
void swap(char *a, char *b);

/* ------ printer.c ------ */
void print_prompt(char *s);
void print_number(int);
int print_char(char);
int print_proccontent(char *path);

/* ------ print_env.c ------ */
void print_env(int pid);

/* ------ freearray_strings.c ------ */
void free_split(char **grid);

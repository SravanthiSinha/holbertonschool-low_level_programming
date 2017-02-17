#include <stddef.h>
typedef int (*funcPtr)(int,int);
int op_add(int,int);
int op_sub(int,int);
int op_div(int,int);
int op_mul(int,int);
int op_mod(int,int);

int (*get_op_func(char c))(int ,int)
{
  int i;
  char op[5] = {'+','-','*','/','%'};
  //  int (*p[5])(int,int) ={op_add,op_sub,op_mul,op_div,op_mod};
  funcPtr p[5] = {op_add,op_sub,op_mul,op_div,op_mod};
  for(i = 0;i<5;i++)
    if(c == op[i])
      return *p[i];
  return NULL;  
}

int print_char(char c);

/* This is the prototype of the function power */
long power(unsigned long , int);

/*This is the prototype of the function print_number */
void print_number(int);

/*This is the prototype of the fucntion get_len*/
int get_len(unsigned long);

/* This is the prototype of the function print_numberchar*/
void print_numberchar(unsigned long);

/* The function print_number takes an integer
 * and prints it.
 * uses print_numberchar for both the negative and positive number
 * It takes a argument (int) and
 * returns nothing (void)
 */
void print_number(int x)
{
  if (x==0)print_char('0'); 
  else if(x<0) /*check if a number is a negative*/
    {
      print_char('-'); 
      print_numberchar((unsigned long)x*-1);/*used long to handle min of int*/
    }
  else{
    print_numberchar(x);
  }
}

/* The function print_numberchar prints
 * a number by parsing it
 * It takes a argument (unsigned long) and
 * returns nothing (void)
 */
void print_numberchar(unsigned long x){
  long result;
  int len,p;
  len=get_len(x);/*store length of the number*/
  p=len;
  while(p<=len && x!=0)
    {
      result=x/power(10,p-1);/*get the each character of a number*/
      print_char(result+48);
      x=x-(result*power(10,p-1));
      p--;
      len=get_len(x);
      while(p>len) 
	{
	  print_char('0');
	  p--;
	}
    }
}
/* The function get_len
 * returns the length of the input number
 * It takes a argument (unsigned long void) and
 * returns length of number (int)
 */
int  get_len (unsigned long  value){
  int l=1;
  while(value>9)
    {
      l++;
      value/=10;
    }
  return l;
}

/* The function power computes the power recursively
 * and returns the value of x ^ y
 * It takes 2 arguments (unsigned long,int) and
 * returns a number  (long)
 */

long power(unsigned long  x,int y)
{
  if( y == 0)
    return 1;
  else if (y%2 == 0)
    return power(x, y/2)*power(x, y/2);
  else
    return x*power(x, y/2)*power(x, y/2);
}

void print_array(int *a, int n)
{
  int i=0;
  while(i<n)
    {
    print_number(*(a+i));
    if(i<n-1)
      {
	print_char(',');
	print_char(' ');
      }
    i++;
    }
}

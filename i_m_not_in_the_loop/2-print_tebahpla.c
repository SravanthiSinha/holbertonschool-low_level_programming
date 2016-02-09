/* This is the prototype of the function
 * print_char
 */
int print_char(char);

/* The function print_tebahpla prints
 * the alphabets a-z in reverse order.
 * It takes no argument (void) and
 * returns nothing (void)
 */
void print_tebahpla(void)
{
  char c;
  for(c='z';c>='a';c--)/* looping through alphabets in the reverse order*/
      print_char(c);  
}

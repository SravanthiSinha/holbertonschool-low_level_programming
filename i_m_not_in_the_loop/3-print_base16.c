/* This is the prototype of the function
 * print_char
 */
int print_char(char);

/* The function print_base16 prints
 * the Hexadecimal Range (ie)"0-F"
 * It takes no argument (void) and
 * returns nothing (void)
 */
void print_base16(void)
{
  int i=0;
  for(i=48;i<58;i++) /* looping the Dec values from 48to58 which are ASCII 0-9*/
     print_char(i);
  for(i=65;i<71;i++) /* looping the Dec values from 65to71 which are ASCII A-F*/
     print_char(i);
}

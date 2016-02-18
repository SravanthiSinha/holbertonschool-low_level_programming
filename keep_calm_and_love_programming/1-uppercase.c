/* The function uppercase takes 
 * a character and converts a letter to upper case, if possible.
 * It takes a argument (unsigned long) and
 * returns nothing (void)
 */

char uppercase(char c)
{
  if(c>=97 && c<=122)
    return c-32;
  else return c;
}

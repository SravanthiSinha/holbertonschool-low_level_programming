/* The function lowercase takes 
 * a character and converts a letter to lower case, if possible.
 * It takes a argument (char c) and
 * returns a character (char)
 */

char lowercase(char c)
{
  if(c>=65 && c<=90)
    return c+32;
  else return c;
}

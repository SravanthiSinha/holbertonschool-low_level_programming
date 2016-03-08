#include <limits.h>

/* The function is_number checks 
 * whether a charactes is a number
 * It takes 2 arguments (char ,int) and
 * returns a number  (int)
 */

int is_number(char c, int option)
{
  if (option == 0)
    {
      if (c == 45)
        return (-1);
      else if (c >= 48 && c <= 57)
        return(c - 48);
      return (10);
    }
  else
    if (c >= 48 && c <= 57)
      return (1);
  return (0);
}

/* The function string_to_integer
 * returns the first number contained in a string
 * It takes 1 argument (char *) and
 * returns a number  (int)
 */


int string_to_integer(char *s)
{
  int i, no, r, sign;

  for (i = 0, no = 0, sign = -1; *(s + i) != '\0'; i++)
    {
      r = is_number(*(s + i), 0);
      if (r == -1 && !(is_number(*(s + i - 1), 1)))
	sign *= r;
      else if (r != 10)
	if ( no < INT_MIN / 10 || ( no == INT_MIN / 10 && no == 9))
	  return (0);
	else
	  no = (no * 10) - r;
      else if (is_number(*(s + i - 1), 1))
	break;
    }
  if (sign < 0 && no == INT_MIN)
    return (0);
  else
    no *= sign;

  return(no);
}

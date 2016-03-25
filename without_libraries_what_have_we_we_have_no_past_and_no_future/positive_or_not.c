int print_char(char);
/* The function positive_or_not prints P,N,Z based on input
 * P if the number is positive,
 * N if the number is negative,
 * and Z if the number is zero.
 * It takes an integer (int) and
 * returns nothing (void)
 */
void positive_or_not(int a)
{
  if(a>0) print_char('P'); /*check if the number is positive*/
  else if(a<0) print_char('N'); /*check if the number is negative */
  else if(a==0) print_char('Z'); /*check if the number is equal to zero */
}

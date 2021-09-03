
#include <stdio.h>


int main(int argc, char **argv) {
  int n, k, l, r, t, d, i;
  char str[65], s;

  /* Make the user enter a non-negative integer */
  printf("Please enter a non-negative integer: ");
  scanf("%d", &n);
  while (n < 0) {
    printf("Sorry, your input is incorrect.\n");
    printf("Please enter a non-negative integer: ");
    scanf("%d", &n);
  }

  /* Convert the integer to reversed binary: e.g. 6 gets converted to 011 */
  if (n == 0) {
    /* Special case for n = 0 */
    str[0] = '0';
    str[1] = '\0';
  } else {
    /* Common case */
    k = n;
    i = 0;
    while (k > 0) {
      r = k % 2;
      str[i] = '0' + r;
      k /= 2;
      ++l;
      ++i;
    }
    str[i] = '\0';
    
  }
  /* The conversion made the string come out reversed, so reverse the string again. 

     DO NOT USE A COPY OF THE STRING. DO NOT USE ANY LIBRARY FUNCTION
     (no strlen or other !)

  */

  for (i = 0; i < l/2; ++i) {
    s = str[i];
    str[i] = str[l - i - 1];
    str[l - i - 1] = s;
  }
  
  /* Display the number and the string */
  printf("The decimal number %d is %s in binary.\n", n, str);
  
  return 0;
}

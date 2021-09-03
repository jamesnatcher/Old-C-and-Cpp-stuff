
#include <stdio.h>


int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  int i;
  char c;
  int is_all_digits;
  int d, n;

  /* Get the user to enter one string */
  printf("Please enter a string which forms a number, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  } 
  str[i] = '\0';

  /* Go over the string and check if it is made of digits only (0-9). */
  is_all_digits = 1;
  for (i=0; str[i] != '\0'; i++) {
    if (!(('0' <= str[i]) && (str[i] <= '9'))) {
      is_all_digits = 0;
      break;
    }
  }

  if (is_all_digits) {
    /* Go over the string and convert each digit in the string to the corresponding integer.
       
       Put that integer into variable d.

       '0' -> 0
       '1' -> 1
       ...
       '9' -> 9

       Then use the variable d to convert the string (of digits) into
       the corresponding integer number.
       
       Put the result into n.

       Example:

       17   =  1 * 10 + 7
       123  =  12 * 10 + 3 = (1 * 10 + 2) * 10 + 3
       1664 =  ((1 * 10 + 6) * 10 + 6) * 10 + 4

       15948    Per digit, for example the 5, we need to  
        ^       multiply the number we have by 10 and add the digit.

       n = 0     n * 10 + 1 -> 1      -> n = 1
       n = 1     n * 10 + 5 -> 15     -> n = 15
       n = 15    n * 10 + 9 -> 159    -> n = 159
       n = 159   n * 10 + 4 -> 1594   -> n = 1594
       n = 1594  n * 10 + 8 -> 15948  -> n = 15948
                          ^
			  d
    */
    n = 0;
    for (i=0; str[i] != '\0'; i++) {
      n *= 10;
      d = str[i] - '0';
      n += d;
    }

    printf("The string \"%s\" contains the number %d.\n", str, n);
  } else {
    printf("The string \"%s\" contains characters which are no digits.\n", str);
  }
  
  return 0;
}

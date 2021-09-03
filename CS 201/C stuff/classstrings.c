
#include <stdio.h>

int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  int i;
  char c;
  int len;
  int is_palindrome, l, r;

  /* Get the user to enter two strings */
  printf("Please enter a string, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  } 
  str[i] = '\0';

  /* Print out the string entered by the user

     For the sake of the exercise, do not use "%s" in a printf,
     but print the string one character at a time.
     
  */
  for (i=0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  /* Determine the length of the string str. Put the answer into
     len. 

     e.g. Hello has 5 characters, so its length is 5.
     
     DO NOT USE strlen !

  */
  for (len=0; str[len] != '\0'; len++);

  printf("The string \"%s\" contains %d characters.\n", str, len);

  /* Test if the string str is a palindrome.

     A palindrome is a word that reads the same from the left as from the right.

     Examples:

     "radar"   is a palindrome
     "madam"   is a palindrome
     "racecar" is a palindrome
     ""        is a palindrome
     "a"       is a palindrome
     "abba"    is a palindrome
     "but"     is not a palindrome

     The answer needs to go (as a boolean) into variable is_palindrome.

     The algorithm is a modified left-hand/right-hand algorithm:

     radar
     ^   ^

     compare  if different: done, the answer is no
              otherwise: move hands, continue

     stop when the hands are at the same position or crossed.
     
     Start with setting the is_palindrome variable to 1 (meaning "I have faith that this is a palindrome")
     At the first offending character, loose faith in the "palindromeness" of the string. 
     
  */
  is_palindrome = 1;
  l = 0;
  r = len - 1;
  while (l < r) {
    if (str[l] != str[r]) {
      is_palindrome = 0;
      break;
    }
    l++;
    r--;
  }

  if (is_palindrome) {
    printf("The string \"%s\" is a palindrome.\n", str);
  } else {
    printf("The string \"%s\" is not a palindrome.\n", str);
  }

  /* Convert all lower-case letters to upper-case, modifying the
     string IN PLACE (no copy), leaving all other characters as-is.

     DO NOT USE ANY FUNCTIONALITY OUT OF string.h OR ctype.h

  */

  /* TODO */

  printf("The string converted to upper-case is \"%s\".\n", str);

  return 0;
}

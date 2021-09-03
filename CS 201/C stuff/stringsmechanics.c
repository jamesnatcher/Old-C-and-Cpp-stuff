
#include <stdio.h>

/* Returns the length of the string str, i.e. the number of characters
   before the end marker '\0'.

   DO NOT USE strlen TO IMPLEMENT THIS FUNCTION!

*/
int string_length(char string[]) {
  int len; 
  for (len=0; string[len] != '\0'; len++);
  return len;
}

/* Rotates the string str one character to the right, i.e. copies the
   last character into the first one, shifting all characters to the
   right.

   This function may use the string_length function defined above.

   THIS FUNCTION MAY NOT USE strlen AND IT MAY (AND TECHNICALLY
   CANNOT) USE A COPY OF THE INPUT STRING.
   
   Example: if the entering string is "HELLO", it gets modified to
            "OHELL".

*/
void rotate_string(char string[]) {
  int l;
  char t;
  l = string_length(string);
  t = string[l - 1];
  for (int i = l - 1; i > 0; --i) {
    string[i] = string[i - 1];
  }
  string[0] = t;
}

/* The main program

   Do not change this program in any place.

*/
int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str[BUF_LEN];
  int i;
  char c;
  int len;

  /* Get the user to enter a string */
  printf("Please enter a string, finishing the entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  } 
  str[i] = '\0';

  /* Print out the string */
  printf("You entered: \"%s\"\n", str);

  /* Compute the length of the string */
  len = string_length(str);

  /* Display the length of this string */
  printf("This string contains %d characters.\n", len);
  printf("\n");

  /* Display the string repeatedly */
  for (i=0; i<len; i++) {
    printf("%s\n", str);
    rotate_string(str);
  }
  printf("%s\n", str);
  
  return 0;
}

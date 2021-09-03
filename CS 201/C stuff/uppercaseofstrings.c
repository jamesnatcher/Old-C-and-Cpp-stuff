
#include <stdio.h>

/* Gets input from the user in the form of a string. The string
   contains up to n characters, including the end marker '\0'.

   No changes are needed here.

*/
void input_string(char str[], int n) {
  char c;
  int i;
  
  if (n < 1) return;  
  for (i=0; i<n-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str[i] = c;
  } 
  str[i] = '\0';
}

/* Removes all characters from the string str that are no upper case
   letters.

   The string is modified in place, i.e. the string contains both the 
   input to the function and the output of the function.

   Examples:

   "HELLO WORLD" is transformed into "HELLOWORLD"

   "hello World" is transformed into "W"

   "aaaaaa"      is transformed into ""

   "HwEoLrLlOd"  is transformed into "HELLO"

   "a"           is transformed into ""

   CAUTION: THIS FUNCTION MAY (AND TECHNICALLY CANNOT) USE A 
   COPY OF THE STRING! 

   The function must achieve its goal by finding all positions at
   which a character that is not an upper case letter is located and
   it must remove these characters by moving all characters right to
   this (or these) position(s) to the left, *including* the end
   marker.

   CAUTION: BE SURE TO NEVER READ THE -1-TH ELEMENT OF THE ARRAY THE
   STRING IS FORMED OF, NOR THE CHARACTER BEYOND THE END OF THE
   STRING.
   
   WARNING: THIS ALGORITHM IS EASY ("TRIVIAL") ONCE YOU FIND IT BUT IT
   WILL PRODUCE SOME FRUSTRATION IN THE BEGINNING!!

*/
void remove_anything_but_upper_case(char str[]) {
  int len, upperlen;
  char t;
  for (len = 0; str[len] != '\0'; ++len);

  upperlen = 0;
  for (int i =0; i <= len; ++i){
    if ((str[i] >= 'A') && (str[i] <= 'Z')) {
      t = str[i];
      str[upperlen] = t;
      ++upperlen;
    }
  }
  str[upperlen] = '\0';  
}

/* The main function. 

   No change is needed here.

*/
int main(int argc, char **argv) {
  const int BUF_LEN = 4095;
  char str[BUF_LEN];
  
  printf("Please enter a string. Hit enter when done.\n");
  input_string(str, BUF_LEN);

  printf("The string you entered is \"%s\".\n", str);

  remove_anything_but_upper_case(str);

  printf("The string with only the upper case letters left is \"%s\".\n", str);

  return 0;
}

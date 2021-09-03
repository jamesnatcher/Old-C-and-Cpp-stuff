
#include <stdio.h>

int main(int argc, char **argv) {
  const int BUF_LEN = 128;
  char str1[BUF_LEN];
  char str2[BUF_LEN];
  int i;
  char c;
  int comp;
  int nullindex, clear;

  /* Get the user to enter two strings */
  printf("Please enter two strings, finishing each entry by pressing Enter.\n");
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str1[i] = c;
  } 
  str1[i] = '\0';
  
  for (i=0; i<BUF_LEN-1; i++) {
    scanf("%c", &c);
    if (c == '\n') {
      break;
    }
    str2[i] = c;
  } 
  str2[i] = '\0';

  comp = 0;  

  while ((str1[i] == '\0') || (str2[i] == '\0')) {
    if (str1[i] < str2[i]) {
      comp = -1;
      break;
    }
    else if (str1[i] > str2[i]) {
      comp = 1;
      break;
    }
    ++i;
  }


  if (comp < 0) {
    printf("The string \"%s\" figures in a dictionary before the string \"%s\".\n", str1, str2);
  } else {
    if (comp > 0) {
      printf("The string \"%s\" figures in a dictionary after the string \"%s\".\n", str1, str2);
    } else {
      printf("The two strings \"%s\" and \"%s\" are equal.\n", str1, str2);
    }
  }

  return 0;
}

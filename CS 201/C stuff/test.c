#include <stdio.h>

char inverse_key_cesar(char k) {
  char inverse_key, r;
  int k_pos;
  k_pos = k - 'A';
  r = (26 - k_pos) % 26;
  inverse_key = r + 'A';
  return inverse_key;
}

int main(void) {

  char c;
  
  scanf("%c", &c);
  printf("%c", inverse_key_cesar(c));
  


  return 0;
}
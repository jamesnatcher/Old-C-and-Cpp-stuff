/* Program for encoding and decoding with the Vigenere cipher.

   (C) 2020 UAA

   Program written by Chr. Lauter.

   Program modified and completed by 

   Paul James Natcher

*/

#include <stdio.h>

/* CAUTION: None of the functions to be written below may use any functions
   like strlen, strcpy from any library.
*/



/* Gets input from the user in the form of a string. The string
   contains up to n characters, including the end marker '\0'.
   
   This function is completely given. No changes are needed.

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


/* Cleans up clear text. Changes all lower case letters to upper
   case. Leaves upper case letters untouched. Changes all other
   characters to space.

   This function is completely given. No changes are needed.

*/
void cleanup_text(char str[]) {
  int i;

  for (i=0; str[i] != '\0'; i++) {
    if (!(('A' <= str[i]) && (str[i] <= 'Z'))) {
      if (('a' <= str[i]) && (str[i] <= 'z')) {
	str[i] = (str[i] - 'a') + 'A';
      } else {
	str[i] = ' ';
      }
    }
  }
}


/* Cleans up key text. Changes all lower case letters to upper
   case. Leaves upper case letters untouched. Removes all other
   characters.

   This function is completely given. No changes are needed.

*/
void cleanup_key(char str[]) {
  int i, j;

  for (i=0; str[i] != '\0'; i++) {
    if (!(('A' <= str[i]) && (str[i] <= 'Z'))) {
      if (('a' <= str[i]) && (str[i] <= 'z')) {
	str[i] = (str[i] - 'a') + 'A';
      } else {
	for (j=i+1; str[j] != '\0'; j++) {
	  str[j-1] = str[j];
	}
	str[j-1] = '\0';
	i--;
      }
    }
  }
}


/* Given an upper case letter c, returns the position of this letter
   in the English alphabet.

   For 

   'A'   returns 0
   'B'   returns 1
   'C'   returns 2
   ...
   'Z'   returns 25.

   The function does not need to work for any character other than an
   upper case letter. It may return any other, non-sense value in this
   case, like 17, -42 etc.

*/
int letter_to_number(char c) {
  int num;
  num = c - 'A';
  return num;
}


/* Given a number n between 0 and 25, indicating a position in the
   English alphabet, returns the corresponding upper case letter.

   For

   0   returns 'A'
   1   returns 'B'
   2   returns 'C'
   ...
   25  returns 'Z'.
   
   The function does not need to work for any value n less than 0 or
   greater than 25. It may return any other, non-sense value in this
   case, like ' ', '%', '?' etc.

*/
char number_to_letter(int n) {
  char c;
  c = 'A' + n;
  return c;
}


/* Applies the Cesar cipher on the clear text letter t, using the key
   letter k.

   If t is the space character ' ', returns it as-is.

   Otherwise, t is an upper case letter and k is an upper case
   letter. The function uses both letter to compute and return the
   Cesar-encoded letter.

   The Cesar cipher does the following: it determines the positions of
   both the clear text letter t and the key letter k in the
   alphabet. The function may do this by calling the letter_to_number
   function twice. The cipher then adds both positions together. It
   divides that sum by 26, discards the quotient and keeps the
   remainder. It returns the letter corresponding to the position in
   the alphabet given by that remainder.

*/
char cesar(char t, char k) {
  int t_pos, k_pos, pos_sum, r;
  char cesared;
  
  if (t == ' ') {
    return t;
  }
  else {
    t_pos = letter_to_number(t);
    k_pos = letter_to_number(k);
    pos_sum = t_pos + k_pos;
    r = pos_sum % 26;
    cesared = number_to_letter(r);
    return cesared;
  }
}


/* Returns the inverse key letter for the given key letter for the
   Cesar cipher.

   The inverse key letter is computed as follows:

   The function determines the position of the upper case letter k in
   the alphabet. It subtracts that position from 26. It divides the
   difference by 26, discards the quotient and keeps the remainder. It
   returns the letter in the position of the alphabet given by that
   remainder.

*/
char inverse_key_cesar(char k) {
  char inverse_key, r;
  int k_pos;
  k_pos = letter_to_number(k);
  r = (26 - k_pos) % 26;
  inverse_key = number_to_letter(r);
  return inverse_key;
}


/* Encodes the clear text in the string text using the key text in the
   string key, applying the Vigenere cipher.

   Puts the encoded text back into the string text, hence modifying
   the text in place. 
   
   Does not modify the key string.

   The Vigenere cipher works as follows:

   It goes over the text and the key one character after the other.
   It encodes the 0-th text character using the 0-th key character,
   applying the Cesar cipher on this text character and key character.
   It then encodes the 1-th text character with the 1-th key
   character, applying the Cesar cipher. It continues like this until
   the end of the text string. If the key string is shorter than the
   text string, it starts over at the 0-th character of the key string
   whenever the end of the key string is hit.

   CAUTION: THE KEY STRING MAY BE SHORTER THAN THE TEXT STRING. YOUR
   CODE NEEDS TO ACCOUNT FOR THIS.

   Even if the Cesar cipher returns a character as-is, the
   corresponding key text character is "consumed".

   The function may assume that both the text and the key strings are
   non-empty, that the text string contains nothing but upper case
   letters or spaces and that the key string contains nothing but
   upper case letters. If these conditions are not satisfied, the
   function may behave like it wants to.

   YOU DO NOT NEED TO CHECK THESE CONDITIONS (non-empty strings made
   of upper case letters etc.). NO if STATEMENT IS NEEDED FOR THIS.

*/
void encode_vigenere(char text[], char key[]) {
  int text_len, key_len, key_index;
  char temp_char;

  for (text_len = 0; text[text_len] != '\0'; ++text_len);
  for (key_len = 0; key[key_len] != '\0'; ++key_len);

  key_index = 0;
  for (int i = 0; i < text_len; ++i) {
    temp_char = cesar(text[i], key[key_index]);
    text[i] = temp_char;
    key_index = (key_index + 1) % key_len;
  }
}


/* Computes the inverse (decryption) key for the Vigenere
   cipher. Modifies the key string so that after the call to this
   function it contains the inverse key.

   The inverse key for the Vigenere cipher is obtained by taking the
   inverse key of the Cesar cipher for each character in the Vigenere
   key string.

   The function hence applies the Cesar inverse key function on
   the 0-th character and puts the obtained inverse key letter back
   into the 0-th position of the string. It then continues the 
   same way for the 1-th character of the key and so on until 
   the end of the key is encountered.

   This function may assume that all characters in the key string are
   upper case letters.

*/
void inverse_key_vigenere(char key[]) {
  char temp_char;

  for (int i = 0; key[i] != '\0'; ++i) {
    temp_char = inverse_key_cesar(key[i]);
    key[i] = temp_char;
  }
}


/* The main function. 

   This function is completely given. No changes are needed.

   CAUTION: DO NOT CHANGE ANYTHING IN THIS FUNCTION! 

   If your compiler tells you that there is an error with a call of
   any of the functions defined above and called below, the issue is
   with your function definition above and not with the call below!

*/
int main(int argc, char **argv) {
  const int BUF_LEN = 1024;
  char text[BUF_LEN];
  char key[BUF_LEN];

  /* Get the clear text input */
  printf("Please input some text. Press enter when done.\n");
  input_string(text, BUF_LEN);

  /* Get the key text input */
  printf("Please input some key text. Use letters only. Press enter when done.\n");
  input_string(key, BUF_LEN);

  /* Clean up the clear text and the key text */
  cleanup_text(text);
  cleanup_key(key);

  /* Check if both the text and the key are not empty after the clear
     up 
  */
  if ((text[0] != '\0') && (key[0] != '\0')) {
    /* Print the clear text and the key */
    printf("The text that is going to be encoded is: \"%s\"\n", text);
    printf("The key that is going to be used is:     \"%s\"\n", key);

    /* Encode the clear text using the key */
    encode_vigenere(text, key);

    /* Print the cipher text */
    printf("The encoded text is:                     \"%s\"\n", text);

    /* Compute the inverse cipher key */
    inverse_key_vigenere(key);

    /* Print the decryption key */
    printf("The decryption key is:                   \"%s\"\n", key);
  } else {
    /* Print an error message and do nothing else */
    printf("Either the text or the key is empty.\n");
  }

  return 0;
}

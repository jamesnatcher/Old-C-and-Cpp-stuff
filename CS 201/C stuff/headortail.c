#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeadsOrTails(char* decisionString) {
   int i;
   i = rand();
   if (i % 2 == 0) {
      strcpy(decisionString, "heads");
   }
   else {
      strcpy(decisionString, "tails");
   }
}


int main(void) {
   int flipnum, i;
   char decisionString[10];
   
   srand(2);  /* Unique seed */

   scanf("%d", &flipnum);
   
   for (i = 0; i < flipnum; ++i) {
      HeadsOrTails(decisionString);
      printf("%s\n", decisionString);
   }
   
   return 0;
}
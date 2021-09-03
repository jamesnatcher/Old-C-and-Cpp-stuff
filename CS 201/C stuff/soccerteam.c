#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int rating[5], number[5], i;
    char yup, choice, menu[200] = "MENU\nu - Update player rating\na - Output players above a rating\nr - Replace player\no - Output roster\nq - Quit\n\nChoose an option:";
   
    for (i = 0; i < 5; ++i) {
      printf("Enter player %d's jersey number:\n", i+1);
      scanf("%d", &number[i]);
      printf("Enter player %d's rating:\n", i+1);
      scanf("%d", &rating[i]);
    }
    printf("\nROSTER\n");
    for (i=0; i<5; ++i) {
      printf("Player %d -- Jersey number: %d, Rating: %d\n", i+1, number[i], rating[i]);
    } 
  
    printf("\n--------------------------\n");
    

    while (yup != 'q') {
      printf("\nChoose a yup: ");
      scanf("%c", &yup);
      printf("\nyup is now %c", yup);
    }

    return 0;
}
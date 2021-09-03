#include <stdio.h>
#include <math.h>

int main(void) {
   int mm;
   int miles;
   int yards;
   int feet;
   int inches;

   printf("Enter a the measurement in millimeters: ");
   scanf("%d", &mm);

   miles = (mm / 25.4 / 12 / 3/ 1760);
   yards = ((mm / 25.4 / 12 / 3/ 1760) - miles) * 1760;
   feet = ((((mm / 25.4 / 12 / 3/ 1760) - miles) * 1760) - yards) *3 ;
   inches = (double)(((((mm / 25.4 / 12 / 3/ 1760) - miles) * 1760) - yards) * 3) * 12 ;

   printf("%dmm is as long as %d miles, %d yards, %d feet, and %d inches\n", mm, miles, yards, feet, inches);

   return 0;
}
   

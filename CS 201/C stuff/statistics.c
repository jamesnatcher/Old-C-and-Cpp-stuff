//Submitted by Paul James Natcher

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int userNum = 0;
    int tempVal = 0;
    int max;
    int min;
    double avg;
    int sum = 0;
    int numCount = 0;

    printf("Please enter an integer, enter a negative value to stop: ");
    scanf("%d", &userNum);
    tempVal = userNum;
    max = tempVal;
    min = tempVal;

    if (userNum >= 0) {
        while (userNum >= 0) {
            if (userNum > max) {
                max = userNum;
            }
            if (userNum < min) {
                min = userNum;
            }
            sum += userNum;
            ++numCount;

            printf("Please enter an integer, enter a negative value to stop: ");
            scanf("%d", &userNum);

        }
        avg = sum / (double) numCount;
        printf("The minimum of the non-negative values entered is %d\n", min);
        printf("The maximum of the non-negative values entered is %d\n", max);
        printf("The average of the non-negative values entered is %0.6lf\n", avg);
    }
    else {
        printf("You have entered no non-negative values. There is no minimum, maximum and average.\n");
    }

    return 0;
}
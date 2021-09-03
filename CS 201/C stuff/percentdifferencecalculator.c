#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double a, b, c;
    printf("Enter the first and the second number: \n");
    scanf("%lf %lf", &a, &b);

    c = (fabs(a - b)/((a + b)/2)) * 100;

    printf("The percent difference is %0.1lf%%", c);

    return 0;
}
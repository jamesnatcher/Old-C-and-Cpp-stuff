#include <stdio.h>
#include <math.h>

double factoring(int num){
    int i;
    double product = 1;
    for (i = num; i > 0; --i) {
        product *= i;
    }
    return product;
}

int main(void) {
    int userChoice, x, y, z;
    double answer;

    printf("Select the type of permutation or combinations:\n1) Permutation with repitition\n2) Permutation w/o repitition\n3) Combination\n");
    printf("Selection: ");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case (1):
        printf("\nFormula = n ^ r\nPlease enter x: ");
        scanf("%d", &x);
        printf("Please enter y: ");
        scanf("%d", &y);
        printf("The answer is: %0.2lf", pow(x, y));
        break;
    case (2):
        printf("\nFormula =  n! / (n – r)!\nPlease enter x: ");
        scanf("%d", &x);
        printf("Please enter y: ");
        scanf("%d", &y);
        answer = factoring(x) / factoring(x - y);
        printf("The answer is: %0.2lf\n", answer);
        break;
    case (3):
        // TODO
        break;
    default:
        break;
    }


    return 0;
}
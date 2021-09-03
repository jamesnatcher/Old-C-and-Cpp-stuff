#include <stdio.h>

int multiplication(int a, int b) {
    if (b == 0) {
        return 0;
    }
    else if (b == 1) {
        return a;
    }
    else if (b % 2 == 0) {
        return multiplication((a + a), (b / 2));
    }
    else {
        return a + multiplication((a + a), ((b - 1)/2));
    }
}

int main(void) {
    int a, b;

    printf("\nPlease enter a non-negative integer: ");
    scanf("%d", &a);
    printf("Please enter another non-negative integer: ");
    scanf("%d", &b);

    printf("\nProduct using Russian Peasant Multiplication: %d\n", multiplication(a, b));
    printf("Product using C operator *: %d\n\n", a * b);


    return 0;
}
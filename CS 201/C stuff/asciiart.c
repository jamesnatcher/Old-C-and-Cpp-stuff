#include <stdio.h>

int main(void) {
    int n;

    printf("Please enter a number between 1 and 18 (both included): ");
    scanf("%d", &n);

    while ((n<1) || (n > 18)){
        printf("Please enter a number between 1 and 18 (both included): ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; ++i) {
        printf("\n");
        if (i % 2 == 0) {
            for (int j = 0; j < n - i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < (2 * i + 1) ; ++j) {
                printf("*");
            }
        }
        else {
            for (int j = 0; j < n -1; ++j) {
                printf(" ");
            }
            printf("***");
        }
    }

    return 0;
}
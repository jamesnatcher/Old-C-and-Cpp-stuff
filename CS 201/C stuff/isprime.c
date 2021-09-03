#include <stdio.h>

int main(void) {
    int n;
    
    printf("Please enter a positive integer number: ")
    scanf("%d", &n);
    while (n < 1) {
        print("Sorry input is incorrect.");
        printf("Please enter a positive integer number: ");
        scanf("%d", &n);
    }
    
    for (int i = n - 1; i > 2; --i){
        if (n % i == 0) {
            printf("The number %d is not prime", n);
        }
        else {
            printf("The number %d is prime", n);
        }
    }


    return 0;
}
#include <stdio.h>


int power(int k, int n) {
    if (n == 0) return 1;
    if (n == 1) return k;
    
    if (n % 2 == 0) return power(k * k, n/2);
    return power(k, n - 1) * k;
}




int main(int argc, char **argv) {
    int k, n, p;

    scanf("%d %d", &k, &n);

    p = power(k, n);

    printf("%d to the power of %d is %d", k, n, p);

    return 0;
}
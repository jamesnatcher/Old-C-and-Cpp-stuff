//submitted by Paul James Natcher

#include <stdio.h>

int main(void) {
    int a, b, c, d, m, n, k, p, q, g, t1, t2, r, s;

    printf("Please enter a first numerator (>= 0): ");
    scanf("%d", &a);
    while (a < 0) {
        printf("Please enter a first numerator (>= 0): ");
        scanf("%d", &a);
    }
    printf("Please enter a first denominator (> 0): ");
    scanf("%d", &b);
    while (b < 1) {
        printf("Please enter a first denominator (> 0): ");
        scanf("%d", &b);
    }
    printf("Please enter a second numerator (>= 0): ");
    scanf("%d", &c);
    while (c < 0) {
        printf("Please enter a second numerator (>= 0): ");
        scanf("%d", &c);
    }
    printf("Please enter a second denominator (> 0): ");
    scanf("%d", &d);
    while (d < 1) {
        printf("Please enter a second denominator (> 0): ");
        scanf("%d", &d);
    }
    
    m = a * d + c * b;
    n = b * d;
    k = m / n;
    p = m % n; 
    q = n;
    t1 = p;
    t2 = q;
    if (p == 0) {
        g = 1;
    }
    else {
        while (t1 != t2){ 
            if (t1 > t2){
                t1 -= t2;
            }
            else {
                t2 -= t1;
            }
        }
        g = t1;
    }
    r = p / g;
    s = q /g;

    
    if ((k == 0) && (r == 0)) {
        printf("%d / %d + %d / %d = 0\n", a, b, c, d);
    }
    if ((k == 0) && (r != 0)) {
        printf("%d / %d + %d / %d = %d / %d\n", a, b, c, d, r, s);  
    }
    if ((k != 0) && (r == 0)) {
        printf("%d / %d + %d / %d = %d\n", a, b, c, d, k);
    }
    if ((k != 0) && (r != 0)) {
        printf("%d / %d + %d / %d = %d + %d / %d\n", a, b, c, d, k, r, s);
    }

    return 0;
}
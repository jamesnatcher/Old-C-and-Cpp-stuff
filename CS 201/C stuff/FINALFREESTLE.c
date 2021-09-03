#include <stdio.h>
#include <string.h>

int main(void) {
    char* a, b;

    scanf("%s", &a);
    scanf("%s", &b);

    if (strcmp(a, b) < 0) {
        printf("%s before %s", a, b);
    }
    if (strcmp(a, b) > 0) {
        printf("%s before %s", a, b);
    }



    return 0;
}
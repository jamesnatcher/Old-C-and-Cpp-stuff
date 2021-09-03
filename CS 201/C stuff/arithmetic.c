//submitted by Paul James Natcher

#include <stdio.h>

int main(void){
	int int1, int2;

	printf("Please enter a first integer number: ");
	scanf("%d", &int1);

	printf("Please enter a second integer number: ");
	scanf("%d", &int2);

	printf("%d + %d = %d\n", int1, int2, int1 + int2);
	printf("%d - %d = %d\n", int1, int2, int1 - int2);
	printf("%d * %d = %d\n", int1, int2, int1 * int2);
	printf("%d / %d = %lf\n", int1, int2, (double)int1 / int2);


	return 0;
}



// submited by Paul James Natcher

#include <stdio.h>

int main(void){
	int num, i, j;

	printf("\nEnter a positive integer: ");
	scanf("%d", &num);

	while (num <= 0) {
		printf("Enter a positive integer: ");
		scanf("%d", &num);
	}
	printf("\n");

	for (i = 0; i < num; ++i) {
		for (j = 0; j < num; ++j){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");

	for (i = 0; i < num; ++i) {
		for (j = 0; j < num; ++j){
			if ((i == 0) || (j == 0) || (i == num-1) || (j == num-1)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n\n");

	for (i = 0; i < num; ++i) {
		for (j = 0; j < num; ++j){
			if (j > i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}

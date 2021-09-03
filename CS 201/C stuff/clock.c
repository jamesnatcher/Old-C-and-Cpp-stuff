// submitted by Paul James Natcher

#include <stdio.h>

int main(void){
	int hour, min;

	printf("Please enter the hours on a 24 hour clock (0-23): ");
	scanf("%d", &hour);
	printf("Please enter the minutes (0-59): ");
	scanf("%d", &min);
	while (((hour < 0) || (hour > 23)) || ((min < 0) || (min >59))) {
		printf("Sorry your input is incorrect.\n");
		printf("Please enter the hours on a 24 hour clock (0-23): ");
		scanf("%d", &hour);
		printf("Please enter the minutes (0-59): ");
		scanf("%d", &min);
	}

	if (hour > 12) {
		if (min > 9){
			printf("%d:%dPM", hour - 12, min);
		}
		else {
			printf("%d:0%dPM", hour - 12, min);
		}
	}
	else if (hour == 12){
		if (min > 9) {
			printf("12:%dPM", min);
		}
		else {
			printf("12:0%dPM", min);
		}
	}
	else if (hour == 0){
		if (min > 9) {
			printf("12:%dAM", min);
		}
		else {
			printf("12:0%dAM", min);
		}
	}
	else {
		if (min > 9) {
			printf("%d:%dAM", hour, min);
		}
		else {
			printf("%d:0%dAM", hour, min);
		}
	}
	printf("\n");


	return 0;
}

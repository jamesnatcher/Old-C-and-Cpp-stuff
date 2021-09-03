//submitted by Paul James Natcher

#include <stdio.h>

int main(void){

	const int N = 42;
	int fibonacci[N], i;
	double ratio[N-1];

	fibonacci[0] = 1;
	fibonacci[1] = 1;

	for (i = 2; i < N; ++i) {
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}
	for (i = 0; i < N; ++i) {
		printf("%d\n", fibonacci[i]);
	}
	for (i = 0; i < N - 1; ++i) {
		ratio[i] = ((double) fibonacci[i+1]/ (double) fibonacci[i]);
	}
	for (i = 0; i < N - 1; ++i) {
		printf("%lf\n", ratio[i]);
	}

	return 0;
}


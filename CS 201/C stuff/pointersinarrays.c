#include <stdio.h>

/* Inputs n doubles, puts them into the array */
void input_doubles(double array[], int n) {
  int i;

  for (i=0; i<n; i++) {
    scanf("%lf", &array[i]);
  }
}

/* Prints n doubles on one line, separated by commas, no comma in the
   end, one newline in all cases, even if n <= 0.
*/
void print_doubles(double array[], int n) {
  int i;

  for (i=0;i<n;i++) {
    printf("%lf", array[i]);
    if (i<n-1) {
      printf(", ");
    }
  }
  printf("\n");
}

/* Function to compute the *index* of the minimum and the maximum of
   the double values in an array

   If n <= 0, give -1 and -1 back to the calling function.
   Otherwise, give the index of the minimum and the index of the maximum back to the caller.

*/
void minmax(int* p_min, int* p_max, double array[], int n) {
	if (n <= 0){
		*p_min = -1;
		*p_max = -1;
		return;
	}

	*p_max = 0;
	*p_min = 0;
	for (int i = 0; i < n; ++i){
		if (array[i] < array[*p_min]){
			*p_min = i;
		}
		if (array[i] > array[*p_max]){
			*p_max = i;
		}
	}
}

int main(int argc, char **argv) {
  const int n = 7;
  double array[n];
  int max, min;

  input_doubles(array, n);
  print_doubles(array, n);

  minmax(&min, &max, array, n);

  printf("The minimum of these values is %lf at position %d in the array.\n", array[min], min);
  printf("The maximum of these values is %lf at position %d in the array.\n", array[max], max);

  return 0;
}
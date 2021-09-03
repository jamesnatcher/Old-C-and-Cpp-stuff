
#include <stdio.h>

/* Prints the elements of an array of integers on one line, separating
   them by commas. Does not print a comma after the last element, but
   prints a newline after the last element.

   Works for an array of any length. The length of the array is given
   by the parameter n.

*/
void print_array(int array[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i < n - 1){
      printf("%d, ", array[i]);
    }
    else {
      printf("%d\n", array[i]);
    }
  }
}

/* Returns a boolean indicating whether the integer k in parameter is
   a prime number.

   Returns 0 if k is not prime, i.e. there exists an integer between 2
   and k-1 (both included) that divides k.

   Returns 1 otherwise.

   This function returns 1 for k = 1, k = 0 and for all negative
   values of k.

*/
int is_prime(int k) {
  int boo;
  boo = 1;
  for (int i = k - 1; i >= 2; --i){
    if (k % i == 0) {
      boo = 0; 
      break;
    }
  }
  if (k <= 1) {
    boo = 1;
  }
  return boo;
}

/* Fills an array of size n with the n first prime numbers, starting
   at 2, put into the array element of index 0.

   Caution: the integer n is the number of the elements in the array. 
   It is not a bound for the last prime number.

   It is not possible to compute the value of the i-th prime number
   with a closed formula.

   A while loop needs to be used.

   Example: for n = 5, fills the array with 

   2 3 5 7 11

   This function calls is_prime repeatedly to do its job.

*/
void fill_with_prime_numbers(int array[], int n) {
  int i, num;
  i = 0;
  num = 2;
  while (i < n) {
    if (is_prime(num)) {
      array[i] = num;
      ++i;
    }
    ++num;
  }
}

/* The main program

   Do not change this program in any place but to change the initial
   value of the constant integer n.

*/
int main(int argc, char **argv) {
  const int n = 15;
  int primes[n];

  fill_with_prime_numbers(primes, n);

  printf("The first %d prime numbers are:\n", n);
  print_array(primes, n);


  return 0;
}

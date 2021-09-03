
#include <stdio.h>
#include <stdlib.h>

/* Searches the array, which must be sorted by increasing values, for
   the value e. Considers only the elements of the array between the
   indices l and r (both included). For the value to have a chance to
   be found, l must be less than or equal to r. The value l is a left
   start index, the value r is a right end index.

   The function returns the index of the element of the array that
   contains the value e, considering only the indices between l and r,
   both included. If e does not figure among the elements of the array
   at indices between l and r, the function returns a negative "dummy"
   value, typically -1.

   The function is recursive and proceeds like a usual search in a
   dictionary or phonebook would proceed:

   If l is greater than r, there are no indices at which the value
   might figure in the array. The function returns -1.

   Otherwise the function computes the index (approximately) in the
   middle between l and r: m = (l + r) / 2. It does not matter if m is
   not precisely in the middle, i.e. if l + r is an odd number.

   If the value e is found at that middle index m, the function
   happily returns that middle index m.

   Otherwise the function compares the value e with the element of 
   the array at that middle index m:

   If e is less than the element of the array at m, the function calls
   itself to search the array in the first half of the current range
   between l and r. The function hence calls itself with an index
   range between l and m - 1. The function returns the index returned
   by the recursive call.

   Otherwise, e is greater than the element of the array at the middle
   index m, and the function calls itself of the second half of the
   current range between l and r.  The function hence calls itself
   with an index range between m + 1 and r. The function returns the
   index returned by the recursive call.

   Example: let the array be 

   1, 2, 4, 7, 9, 12

   and let us search for e = 2.

   In the beginning l = 0, and r = 5.

   As l <= r, the function computes the middle index m = 2.

   At index 2, it finds the element 4.

   As 4 is not equal to the value e = 2 it looks for, the function
   proceeds:

   Since 2 is less than 4, the function calls itself recursively:

   The recursive call needs to find e = 2 in the array 

   1, 2, 4, 7, 9, 12

   between the indices l = 0 and r = 1.

   As l <= r, the function computes the middle index m = 0.

   It finds the element 1 at that middle index 0. 

   As 1 is not equal to e = 2, the function proceeds:

   Since 2 is greater than 1, the function calls itself recursively;

   The recursive call needs to find e = 2 in the array

   1, 2, 4, 7, 9, 12

   between the indices l = 1 and r = 1.

   As l <= r, the function computes the middle index m = 1.

   It finds the element 2 at that middle index 1.

   Since 2 is equal to e = 2, the function has found the index at
   which e appears: it is the middle index 1. It returns that index.

   The recursive call ends, the call before returns that same index 1.
   The recursive call ends, the call before returns that same index 1.
   
   This way the function returns 1 as the index at which the value e = 2 
   appears in the array 

   1, 2, 4, 7, 9, 12

   between the indices l = 0 and r = 5.

*/
int search_aux(int e, int array[], int l, int r) {
  int m;
  if (r >= l) {
    m = (l + r) / 2;
    if (e == array[m]){
      return m;
    }
    else {
      if (e < array[m]) {
        r = m - 1;
        return search_aux(e, array, l, r);
      }
      else {
        l = m + 1;
        return search_aux(e, array, l, r);
      }
    }
  }
  else {
    return -1;
  }
}

/* Searches the array, which must be sorted by increasing values, for
   the value e. The array has n elements.

   The function returns the index of the element of the array that
   contains the value e. If e does not figure among the elements of
   the array, the function returns a negative "dummy" value, typically
   -1.

   The search function is just a wrapper around the auxiliary
   search_aux function above.

*/
int search(int e, int array[], int n) {
  return search_aux(e, array, 0, n-1);
}

/* A function to input an array of size n */
void input_array(int array[], int n) {
  int i;
  
  printf("Please enter %d integers.\n", n);
  for (i=0; i<n; i++) {
    scanf("%d", &array[i]);
  }
}

/* A function to print out an array of size n */
void print_array(int array[], int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d", array[i]);
    if (i<n-1) {
      printf(", ");
    }
  }
  printf("\n");
}

/* A comparison function suitable for the 
   qsort library function used below in main.

   This function uses features of C you do not know yet. Do not be
   scared. You do not need to understand them.

*/
int comp(const void *a, const void *b) {
  int t_a, t_b;

  t_a = *((const int *) a);
  t_b = *((const int *) b);

  if (t_a < t_b) return -1;
  if (t_a > t_b) return 1;
  return 0;
}


/* The main function

   This function uses features of C you do not know yet. Do not be
   scared. You do not need to understand them.

*/
int main(int argc, char **argv) {
  const int n = 10;
  int array[n];
  int e, i;

  /* Ask the user to input values for an array */
  input_array(array, n);

  /* Print out the array as given by the user */
  printf("The input array, not yet sorted is:\n");
  print_array(array, n);

  /* Sort the array using a predefined sorting algorithm from a
     library 
  */
  qsort(((void *) array), ((size_t) n), sizeof(int), comp);

  /* Print out the sorted array */
  printf("The sorted input array:\n");
  print_array(array, n);

  /* Ask the user to enter an integer */
  printf("Please enter an integer: ");
  scanf("%d", &e);

  /* Try to find the integer in the array */
  i = search(e, array, n);

  /* If the "index" returned by the search function is negative the
     integer does not figure in the array. If its non-negative, the
     integer figures at that index.

  */
  if (i < 0) {
    printf("The integer %d does not figure in the array.\n", e);
  } else {
    printf("The integer %d figures in the array at index %d.\n", e, i);
  }

  return 0;
}

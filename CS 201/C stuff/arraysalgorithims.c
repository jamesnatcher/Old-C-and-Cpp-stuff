
#include <stdio.h>


int main(int argc, char **argv) {
  const int NUMBER_ELEMENTS = 8;
  int array[NUMBER_ELEMENTS];
  int copy[NUMBER_ELEMENTS];
  int i;
  int sum, prod, minimum, maximum;
  int element, found, element_idx;
  int t;
  int l, r;

  /* Get user input for array elements */
  printf("Please enter %d integer numbers to fill the array:\n", NUMBER_ELEMENTS);
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    scanf("%d", &array[i]);
  }

  /* Print out the array */
  printf("The array is:\n");
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    printf("%d", array[i]);
    if (i<NUMBER_ELEMENTS-1) {
      printf(", ");
    }
  }
  printf("\n");

  /* Copy the array array in to the copy array */
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    copy[i] = array[i];
  }

  /* Print out the copy */
  printf("The copied array is:\n");
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    printf("%d", copy[i]);
    if (i<NUMBER_ELEMENTS-1) {
      printf(", ");
    }
  }
  printf("\n");

  /* Sum all the elements in the array */
  sum = 0;
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    sum = sum + array[i];
  }
  printf("The sum of all elements in the array is %d.\n", sum);
  
  /* Compute the product of all the elements in the array */
  prod = 1;
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    prod = prod * array[i];
  }
  printf("The product of all elements in the array is %d.\n", prod);

  /* Compute the minimum and the maximum of all the elements in the array */
  minimum = array[0];
  maximum = array[0];
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    if (array[i] < minimum) {
      minimum = array[i];
    }
    if (array[i] > maximum) {
      maximum = array[i];
    }    
  }
  printf("The minimum of all elements in the array is %d.\n", minimum);
  printf("The maximum of all elements in the array is %d.\n", maximum);

  /* Ask user to give us an element to look for */
  printf("Please enter an integer: ");
  scanf("%d", &element);

  /* Search the array for the element element */
  found = 0;
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    if (array[i] == element) {
      element_idx = i;
      found = 1;
      break;
    }
  }

  if (found) {
    printf("The element %d can be found at index %d\n", element, element_idx);
  } else {
    printf("The element %d cannot be found in this array.\n", element);
  }

  /* Rotate the array by one element to the left
     
     WITHOUT USING A COPY OF THE ARRAY.

     Example:

                          0   1   2   3
     If the array is      17, 42, 23, 1664
     it gets changed to   42, 23, 1664, 17

     As a matter of course, one temporary variable t can be used.

  */
  t = array[0];
  for (i=0; i<NUMBER_ELEMENTS-1; i++) {
    array[i] = array[i + 1];
  }
  array[NUMBER_ELEMENTS-1] = t;
  
  /* Print out the array */
  printf("The rotated array is:\n");
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    printf("%d", array[i]);
    if (i<NUMBER_ELEMENTS-1) {
      printf(", ");
    }
  }
  printf("\n");

  /* Rotate the array to the right */
  t = array[NUMBER_ELEMENTS-1];
  for (i=NUMBER_ELEMENTS-1; i > 0; i--) {
    array[i] = array[i - 1];
  }
  array[0] = t;

  /* Print out the array */
  printf("The rotated array is:\n");
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    printf("%d", array[i]);
    if (i<NUMBER_ELEMENTS-1) {
      printf(", ");
    }
  }
  printf("\n");

  /* Reverse the array IN PLACE

     IN PLACE MEANS WITHOUT USING A COPY ARRAY

     e.g. if the array is    


     1  17  42  1664

     it becomes

     1664  42  17  1
     
     Use the left hand right hand algorithm

     1  17  42  1664
     ^          ^
     l          r

     Swap the values at these two hands l and r:

     1664 17 42 1
     
     Then move the left hand to the right and the right hand to the left

     1664  17   42   1
           ^    ^
           l    r

     Continue until the hands cross.

   */

  /* TODO */


  /* Print out the array */
  printf("The reversed array is:\n");
  for (i=0; i<NUMBER_ELEMENTS; i++) {
    printf("%d", array[i]);
    if (i<NUMBER_ELEMENTS-1) {
      printf(", ");
    }
  }
  printf("\n");
 
  return 0;
}

//submitted by Paul James Natcher
#include <stdio.h>

/* TODO: Define 3 functions input, gcd and lcm in such a
   way that the main function below compiles correctly and
   has the correct behavior.

   The input function prompts the user to enter a non-negative
   integer. If the user enters a negative integer, the function prints
   a "sorry" statement and prompts the user again. It keeps on
   prompting until the user enters a non-negative number. The input
   function returns that non-negative integer.

   The gcd function takes two integers in parameter and does the
   following:

   * If one of the integers is zero, it sets the variable g to 1.
   * Otherwise, it uses Euclid's algorithm to compute the greatest
     common divisor of these two numbers. It puts that greatest common
     divisor into g.
   * It ends by returning g.

   The lcm function takes two integers in parameter, computes the
   least common multiple of these two integers and returns that
   result. The lcm function may use the gcd function.

   See Wikipedia at 

   https://en.wikipedia.org/wiki/Least_common_multiple

   for an explanation what the least common multiple of two numbers
   is.

   CAUTION: AS-IS, THIS BOILERPLATE SOURCE CODE FILE DOES NOT COMPILE.

*/

int input() {
  int x;
  printf("Please enter a non-negative integer: ");
  scanf("%d", &x);
  while (x < 0) {
    printf("Sorry, please enter a non-negative integer: ");
    scanf("%d", &x);
  }
  return x;
}
int gcd(a, b){
  int g; 
  if ((a == 0) || (b == 0)) {
    g = 1;
  } 
  else {
    while (a != b) {
      if (a > b) {
        a -= b;
      }
      else {
        b -= a;
      }
    }
    g = a;
  }
  return g;
}
int lcm(a, b) {
  int x, y, z;
  x = a * b;
  y = gcd(a, b);
  z = x / y;
  return z;
}

int main(int argc, char **argv) {
  int a, b;

  a = input();
  b = input();
  
  printf("The greatest common divisor of %d and %d is %d.\n", a, b, gcd(a, b));
  printf("The least common multiple of %d and %d is %d.\n", a, b, lcm(a, b));
 
  return 0;
}

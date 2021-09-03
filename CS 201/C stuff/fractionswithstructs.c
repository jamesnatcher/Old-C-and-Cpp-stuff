
#include <stdio.h>
#include <stdlib.h>
/* DO NOT USE ANY OTHER LIBRARY. DO NOT USE strlen OR strcpy!!! */

/* Declaration of a struct type fraction_t that allows fractions with
   a numerator and a denominator to be represented.
*/
typedef struct fraction_t_struct {
  int num;
  int den;
} fraction_t;

/* A function to end the program on error */
void error() {
  fprintf(stderr, "Division by zero. Exiting.\n");
  exit(1);
}

/* A function to compute the gcd of 2 numbers */
int gcd(int a, int b) {
  int t1, t2;
  
  if ((a == 0) || (b == 0)) return 1;

  if (a > 0) {
    t1 = a;
  } else {
    t1 = -a;
  }
  if (b > 0) {
    t2 = b;
  } else {
    t2 = -b;
  }
  while (t1 != t2) {
    if (t1 > t2) {
      t1 = t1 - t2;
    } else {
      t2 = t2 - t1;
    }
  }
  
  return t1;
}

/* A function to create a reduced fraction out of a 
   numerator and a denominator 
*/
fraction_t make_fraction(int num, int den) {
  int g;
  fraction_t res;

  if (den == 0) {
    error();
  }
  
  g = gcd(num, den);
  res.num = num / g;
  res.den = den / g;
  
  return res;
}

/* Addition of 2 fractions

   p / q + r / s = (p * s + r * p) / (q * s) 

   The returned fraction must be reduced.
*/
fraction_t addition(fraction_t a, fraction_t b) {
  fraction_t added;
  int t;

  added.num = ((a.num * b.den) + (b.num * a.den));
  added.den = (a.den * b.den);
  
  t = gcd(added.num, added.den);

  added.num /= t;
  added.den /= t;

  return added;
}

/* Subtraction of 2 fractions

   p / q - r / s = (p * s - r * p) / (q * s) 

   The returned fraction must be reduced.
*/
fraction_t subtraction(fraction_t a, fraction_t b) {
  fraction_t subtracted;
  int t;

  subtracted.num = ((a.num * b.den) - (b.num * a.den));
  subtracted.den = (a.den * b.den);
  
  t = gcd(subtracted.num, subtracted.den);

  subtracted.num /= t;
  subtracted.den /= t;

  return subtracted;
}

/* Multiplication of 2 fractions

   p / q + r / s = (p * r) / (q * s) 

   The returned fraction must be reduced.
*/
fraction_t multiplication(fraction_t a, fraction_t b) {
  fraction_t multiplied;
  int t;

  multiplied.num = (a.num * b.num);
  multiplied.den = (a.den * b.den);

  t = gcd(multiplied.num, multiplied.den);

  multiplied.num /= t;
  multiplied.den /= t;

  return multiplied;
}

/* Division of 2 fractions

   (p / q) / (r / s) = (p * s) / (q * r) 

   The returned fraction must be reduced.
*/
fraction_t division(fraction_t a, fraction_t b) {
  fraction_t divided;
  int t;

  divided.num = (a.num * b.den);
  divided.den = (a.den * b.num);

  t = gcd(divided.num, divided.den);

  divided.num /= t;
  divided.den /= t;

  return divided;
}

/* Approximates a fraction with a floating-point number.

   The approximation is the real-valued quotient of the numerator
   divided by the denominator.

*/
double approximate_fraction(fraction_t a) {
  double approximation;
  approximation = (double)a.num / (double)a.den;
  return approximation;
}

/* Prints a fraction, like in 1 / 4 

   Does not print a newline.
*/
void print_fraction(fraction_t a) {
  printf("%d / %d", a.num, a.den);
}

/* Prompts the user for a numerator and a denominator.

   Makes a reduced fraction out of the values entered.

*/
fraction_t input_fraction() {
  int num, den, t;
  
  printf("Please enter a numerator: ");
  scanf("%d", &num);
  printf("Please enter a denominator: ");
  scanf("%d", &den);

  t = gcd(num, den);
  num /= t;
  den /= t;

  return make_fraction(num, den);
}

/* The main program.

   No change needed here.

*/
int main(int argc, char **argv) {
  fraction_t a, b, s, d, p, q;

  a = input_fraction();
  b = input_fraction();

  s = addition(a, b);
  d = subtraction(a, b);
  p = multiplication(a, b);
  q = division(a, b);

  print_fraction(a); printf(" + "); print_fraction(b); printf(" = "); print_fraction(s); printf(" = %lf\n", approximate_fraction(s));
  print_fraction(a); printf(" - "); print_fraction(b); printf(" = "); print_fraction(d); printf(" = %lf\n", approximate_fraction(d));
  print_fraction(a); printf(" * "); print_fraction(b); printf(" = "); print_fraction(p); printf(" = %lf\n", approximate_fraction(p));
  print_fraction(a); printf(" / "); print_fraction(b); printf(" = "); print_fraction(q); printf(" = %lf\n", approximate_fraction(q));
  
  return 0;
}

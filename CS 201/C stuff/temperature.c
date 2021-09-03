#include <stdio.h>

int main(void) {
  double tempNum;
  double celsiusNum;

  printf("Enter a temperature (in °F): \n");
  scanf("%lf", &tempNum);

  celsiusNum = (5.0/9.0) * (tempNum - 32.0);

  printf("%0.2lf°F is %0.2lf°C\n", tempNum, celsiusNum);

  return 0;
}

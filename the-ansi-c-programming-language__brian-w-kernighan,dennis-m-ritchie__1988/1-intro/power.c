#include <stdio.h>

int power(int base, int exponent);

int main() {
  /* test power function */
  int i;

  for (i = 0; i < 10; i++) {
    printf("%d %d %d\n", i, power(2, i), power(3, i));
  }
}

int power(int base, int exponent) {
  int result = 1;

  for (int i = 1; i <= exponent; i++)
    result = result * base;

  return result;
}

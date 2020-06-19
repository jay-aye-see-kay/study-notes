#include <stdio.h>

#define LOWER  0
#define UPPER  300
#define STEP   20

int main() {
  int fahr, cel;

  fahr = LOWER;
  while (fahr <= UPPER) {
    cel = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, cel);
    fahr = fahr + STEP;
  }
}

#include <limits.h>
#include <stdio.h>

unsigned rightrot(unsigned x, int num_shifts);

int main() {
  int in_1 = 0b01111110;
  int num_1 = 2;
  int res_1 = 0b10000000000000000000000000011111;
  printf("rightrot tests:\n");
  printf("[%d] - 0b01111110, n=2. Expect 0b10011111\n",
         rightrot(in_1, num_1) == res_1);
  printf("\n\n");
}

unsigned getbits(unsigned x, int position, int num_bits) {
  // push the bits we want to the right
  int right_shifted = (x >> (position + 1 - num_bits));
  // a mask to allow the bits we want
  int mask = ~(~0 << num_bits);
  // remove unwanted bits to the left
  return right_shifted & mask;
}

int get_bit_count(unsigned int n) {
  // make it one indexed
  long num = n;
  num++;
  int count = 0;
  while (num != 2) {
    num /= 2;
    count++;
  }
  return count;
}

unsigned rightrot(unsigned x, int num_shifts) {
  // TODO wrap around case
  int moved_bits = getbits(x, num_shifts - 1, num_shifts);
  int shifted_x = x >> num_shifts;

  int bit_count = get_bit_count(UINT_MAX);
  int shifted_moved_bits = moved_bits << (bit_count - num_shifts + 1);

  return shifted_x | shifted_moved_bits;
}

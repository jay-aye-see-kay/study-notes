#include <stdio.h>

/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

unsigned invert(unsigned x, int position, int num_bits);

int main() {
  printf("invert tests:\n");
  printf("[%d] - 0b11111011, p=2, n=3. Expect 0b11111100\n",
         invert(0b11111011, 2, 3) == 0b11111100);
  printf("[%d] - 0b11111011, p=5, n=3. Expect 0b11000011\n",
         invert(0b11111011, 5, 3) == 0b11000011);
  printf("[%d] - 0b11111011, p=5, n=3. Expect 0b11111011\n",
         invert(0b11000011, 5, 3) == 0b11111011);
  printf("[%d] - 0b11111011, p=5, n=6. Expect 0b11111100\n",
         invert(0b11000011, 5, 6) == 0b11111100);
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

unsigned invert(unsigned x, int position, int num_bits) {
  // get bits to invert, invert them, offset the inverted
  int offset = position + 1 - num_bits;
  int invert_mask = ~(~0 << num_bits) << offset;
  int to_invert = getbits(x, position, num_bits) << offset;
  int inverted = ~to_invert & invert_mask;

  // zero out a place to put them back in
  int x_mask = ~(~0 << num_bits) << offset;
  int masked_x = ~(~x | x_mask);

  // mask them back in
  return masked_x | inverted;
}

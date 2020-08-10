#include <stdio.h>

/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n);

/* prints an unsigned int as a "binary string" like 0b10101010 */
void print_binary(unsigned int number);

int main() {
  printf("getbits tests:\n");
  printf("[%d] - 0b11111011, p=3, n=3. Expect 0b101\n",
         getbits(0b11111011, 3, 3) == 0b101);
  printf("[%d] - 0b11111011, p=4, n=3. Expect 0b110\n",
         getbits(0b11111011, 4, 3) == 0b110);
  printf("[%d] - 0b11010011, p=4, n=3. Expect 0b101001\n",
         getbits(0b11010011, 6, 6) == 0b101001);
  printf("[%d] - 0b11010011, p=7, n=3. Expect 0b110\n",
         getbits(0b11010011, 7, 3) == 0b110);

  printf("\nsetbits tests:\n");
  printf("[%d] - 0b11111010, p=2, n=3. Expect 0b11111111\n",
         setbits(0b11111010, 2, 3, 0b111) == 0b11111111);
  printf("[%d] - 0b11111010, p=5, n=3. Expect 0b11000010\n",
         setbits(0b11111010, 5, 3, 0b000) == 0b11000010);
  printf("[%d] - 0b11111010, p=5, n=3. Expect 0b11010010\n",
         setbits(0b11111010, 5, 3, 0b010) == 0b11010010);
  printf("[%d] - 0b11111010, p=5, n=4. Expect 0b11001010\n",
         setbits(0b11111010, 5, 4, 0b100010) == 0b11001010);

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

unsigned setbits(unsigned x, int position, int num_bits, unsigned y) {
  // getbits of y (the rightmost num_bits)
  int new_bits = getbits(y, num_bits - 1, num_bits);
  // left shift them to overlay the correct position over x
  int offset = position + 1 - num_bits;
  int offset_y = y << offset;

  // set those bits of x to 0
  int x_mask = ~(~0 << num_bits) << offset;
  int masked_x = ~(~x | x_mask);

  // x & y to overlay in place
  return masked_x | offset_y;
}

/* Utility function from: https://stackoverflow.com/a/27627015/7164888
 */
void print_binary_raw(unsigned int number) {
  if (number >> 1) {
    print_binary_raw(number >> 1);
  }
  putc((number & 1) ? '1' : '0', stdout);
}
void print_binary(unsigned int number) {
  printf("0b");
  print_binary_raw(number);
  printf("\n");
}

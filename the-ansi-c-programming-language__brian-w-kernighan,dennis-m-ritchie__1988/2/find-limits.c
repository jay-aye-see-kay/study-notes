#include <float.h>
#include <limits.h>
#include <stdio.h>

/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various */

int main() {
  printf("signed char min    : %d\n", SCHAR_MIN);
  printf("signed char max    : %d\n", SCHAR_MAX);
  printf("unsigned char max  : %d\n", UCHAR_MAX);
  printf("short min          : %d\n", SHRT_MIN);
  printf("short max          : %d\n", SHRT_MAX);
  printf("unsigned short max : %d\n", USHRT_MAX);
  printf("int min            : %d\n", INT_MIN);
  printf("int max            : %d\n", INT_MAX);
  printf("unsigned int max   : %d\n", UINT_MAX);
  printf("long min           : %ld\n", LONG_MIN);
  printf("long max           : %ld\n", LONG_MAX);
  printf("unsigned long max  : %ld\n", ULONG_MAX);
}

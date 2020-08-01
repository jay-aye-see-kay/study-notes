#include <float.h>
#include <limits.h>
#include <stdio.h>

/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 */

#define MAXLINE 1000

int main() {
  int i, lim, c;
  char s[MAXLINE];
  lim = MAXLINE;

  // original loop
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

  // same loop but without logical operators
  for (i = 0; i < lim - 1; ++i) {
    // same basic loop but with these early exits
    if ((c = getchar()) != '\n') break;
    if (c != EOF) break;
    s[i] = c;
  }

  printf("printing this to quiet linter: %s", s);
}

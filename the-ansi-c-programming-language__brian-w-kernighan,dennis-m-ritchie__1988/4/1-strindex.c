#include <stdio.h>

/* Exercise 4-1. Write the function strindex(s,t) which returns the position of
 * the rightmost of `t` in `s` or `-1` if there is none.
 */

int strindex(char s[], char t);

int main() {
  printf("strindex tests:\n");
  printf("[%d] - find rightmost `a`\n", strindex("abc", 'a') == 0);
  printf("[%d] - find rightmost `a` when there's two\n",
         strindex("abca", 'a') == 3);
  printf("[%d] - return -1 when there's no `a`\n", strindex("bcdef", 'a') == -1);
}

int strindex(char str_to_check[], char to_find) {
  int i, found_index;
  found_index = -1;

  for (i = 0; str_to_check[i] != '\0'; i++) {
    if (str_to_check[i] == to_find)
      found_index = i;
  }

  return found_index;
}

#include <stdio.h>

/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

void squeeze(char s[], int c);
void multi_squeeze(char s[], char c[]);
int str_includes(char string[], char c);

int main() {
  char str_1[] = "string";
  char str_2[] = "string";

  squeeze(str_1, 'i');
  multi_squeeze(str_2, "sin");

  printf("result of squeeze(): %s\n", str_1);
  printf("result of multi_squeeze(): %s\n", str_2);
}

/* Original function from book */
void squeeze(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

/* New squeeze function that can delete more than one char
 *
 * I left it modifying the input rather than return something as that's what
 * the book's example did, feels dirty though.
 */
void multi_squeeze(char str_to_mod[], char chars_to_remove[]) {
  int new_idx, old_idx;

  for (new_idx = old_idx = 0; str_to_mod[new_idx] != '\0'; new_idx++) {
    if (!str_includes(chars_to_remove, str_to_mod[new_idx]))
      str_to_mod[old_idx++] = str_to_mod[new_idx];
  }
  str_to_mod[old_idx] = '\0';
}

/* Helper function as multi_squeeze squeeze already had enough index variables.
 * There's probably a library function that does this
 */
int str_includes(char str_to_check[], char c) {
  int i;

  for (i = 0; str_to_check[i] != '\0'; i++) {
    if (str_to_check[i] == c)
      return 1;
  }
  return 0;
}

#include <stdio.h>

/* Exercise 2-5. Write the function any(s1,s2), which returns the first
 * location in a string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 *  strpbrk does the same job but returns a pointer to the 
 */

int any(char s[], char c);

int main() {
  char str_1[] = "string";
  char str_2[] = "string";

  int pos_1, pos_2;

  pos_1 = any(str_1, 'i');
  pos_2 = any(str_2, 'x');

  printf("any(), expect 3: %d\n", pos_1);
  printf("any(), expect -1: %d\n", pos_2);
}

int any(char str_to_check[], char c) {
  int i;

  for (i = 0; str_to_check[i] != '\0'; i++) {
    if (str_to_check[i] == c)
      return i;
  }
  return -1;
}

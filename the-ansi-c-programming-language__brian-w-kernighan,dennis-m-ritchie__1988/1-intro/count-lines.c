#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

int main() {
  int cursor, character_count, line_count, blank_count, tab_count;

  character_count = 0;
  line_count = 0;
  blank_count = 0;
  tab_count = 0;
  while ((cursor = getchar()) != EOF) {
    ++character_count;

    if (cursor == '\n')
      ++line_count;

    if (cursor == ' ')
      ++blank_count;

    if (cursor == '\t')
      ++tab_count;
  }

  printf("character count: %.0d\n", character_count);
  printf("line count: %.0d\n", line_count);
  printf("blank count: %.0d\n", blank_count);
  printf("tab count: %.0d\n", tab_count);
}

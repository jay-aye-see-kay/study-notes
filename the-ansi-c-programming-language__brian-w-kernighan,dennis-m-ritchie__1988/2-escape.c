#include <stdio.h>

void escape(char old_str[], char new_str[]);

int main() {
  char old_str[] = "tab: 	, \\b: \b, \\\\: \\";
  char new_str[100];

  escape(old_str, new_str);

  printf("old_str: `%s`, new_str: `%s`\n\n", old_str, new_str);
}

void escape(char old_str[], char new_str[]) {
  int old_i = 0, new_i = 0;

  while (old_str[old_i] != '\0') {
    switch (old_str[old_i]) {
      case '\t':
        new_str[new_i] = '\\';
        new_i++;
        new_str[new_i] = 't';
        break;

      case '\b':
        new_str[new_i] = '\\';
        new_i++;
        new_str[new_i] = 'b';
        break;

      case '\\':
        new_str[new_i] = '\\';
        new_i++;
        new_str[new_i] = '\\';
        break;

      default:
        new_str[old_i] = old_str[old_i];
    }
    old_i++;
    new_i++;
  }
}

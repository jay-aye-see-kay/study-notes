#include <float.h>
#include <limits.h>
#include <stdio.h>

/* Not an exercise, just want to play with how constants get printed
 */

#define DECIMAL_DOLLAR 36
#define OCTAL_DOLLAR '\044'
#define HEX_DOLLAR '\x24'
#define HEX_DOLLAR_ALT 0x24
#define HEX_DOLLAR_ALT_2 0X24

enum boolean { NO, YES };

enum escapes {
  BELL = '\a',
  BACKSPACE = '\b',
  TAB = '\t',
  NEWLINE = '\n',
  VTAB = '\v',
  RETURN = '\r'
};

int main() {
  printf("dollar sign: %c\n", DECIMAL_DOLLAR);
  printf("dollar sign: %c\n", OCTAL_DOLLAR);
  printf("dollar sign: %c\n", HEX_DOLLAR);
  printf("dollar sign: %c\n", HEX_DOLLAR_ALT);
  printf("dollar sign: %c\n", HEX_DOLLAR_ALT_2);

  printf("no: %d\n", NO);
  printf("yes: %d\n", YES);

  printf("there's a tab between these colons :%c:\n", TAB);
}

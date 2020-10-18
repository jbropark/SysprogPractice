#include <stdio.h>

int main(int argc, char *argv[]) {
  char s[5];
  sprintf(s, "%d%s", 56, argv[1]);
  printf("%s", s);
}

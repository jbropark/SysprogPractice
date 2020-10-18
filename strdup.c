#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *a = argv[1];
  char *d = strdup(a);
  printf("%s %p\n", a, a);
  printf("%s %p\n", d, d);
  strcat(d, strcat(a, a));
  printf("%s %p\n", d, d);

  return 0;
}

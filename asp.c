#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *s = malloc(sizeof(char) * 5); 
  int n = asprintf(&s, "%s", argv[1]);
  printf("%d\n", n);

  printf("%s %s\n", s, s);
  return 0;
}


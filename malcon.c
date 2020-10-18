#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[]) {
  char *s = malloc(sizeof(char));
  printf("%p\n", s);
  free(s);
  for (int i = 1; i < 10; i++) {
    printf("MEANINGLESS\n");
  }
  s = malloc(sizeof(char));
  printf("%p\n", s);
  free(s);
  return 0;
}

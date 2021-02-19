#include <stdio.h>
#include <unistd.h>

int main() {
  int a = dup2(STDOUT_FILENO, 3);
  printf("%d\n", a);
  return 0;
}

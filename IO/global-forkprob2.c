#include <stdio.h>
#include <unistd.h>

void try() {
  fork();
  printf("Example\n");
  fork();
  return;
}

int main() {
  try();
  fork();
  printf("Exmaple\n");
  return 0;
}

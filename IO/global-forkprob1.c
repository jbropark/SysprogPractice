#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  for(int i = 3; i > 0; i--) {
    fork();
  }
  printf("Example\n");
  return 0;
}


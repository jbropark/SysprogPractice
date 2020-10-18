#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  printf("ALARM TEST START\n");

  unsigned int n = alarm(5);

  n = alarm(4);
  pause();

  printf("ALARM Return : %d\n", n);

  return 0;
}

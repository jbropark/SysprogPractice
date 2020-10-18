#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Test Start\n");

  if (fork() == 0) {
    printf("Child pid : %d, ppid : %d\n", getpid(), getppid());
    while(1) {}
  } else {
    printf("Parent pid : %d, ppid : %d\n", getpid(), getppid());
    exit(0);
  }
}

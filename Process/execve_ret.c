#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;

  if ((pid = fork()) == 0) {
    execve("/bin/date", argv, NULL);
    printf("child pid : %d\n", pid);
  }
  printf("pid : %d\n", pid);
  return 0;
}

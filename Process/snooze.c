#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void new_handler(int signo) {
  write(1, "CTRL+C\n", 7);
  return;
}

int main(int argc, char *argv[], char *envp[]) {
  int N = atoi(argv[1]);
  signal(SIGINT, new_handler);
  int n = sleep(N);
  printf("Slept for %d of %d secs.\n", N - n, N);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {

  int N = atoi(argv[1]);

  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);

  sigprocmask(SIG_BLOCK, &mask, NULL);

  for (int i = 0; i <= N; i++) {
    printf("%d / %d\n", i, N);
    fflush(stdout);
    sleep(1);
  }
  printf("Print Done!\n");
  return EXIT_SUCCESS;
}


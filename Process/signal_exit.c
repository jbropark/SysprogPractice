#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void exit_signal(int signo) {
  write(STDOUT_FILENO, "Signal Try to Exit\n", 19); 
  _exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  signal(SIGINT, exit_signal);
  printf("START\n");

  for (int i = 0; i < 10; i++) {
    printf("%d Remain\n", 10 - i);
    fflush(stdout);
    sleep(1);
  }
  
  printf("REACHED HERE!");
  return 0;
}

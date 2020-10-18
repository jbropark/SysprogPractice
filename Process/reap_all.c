#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  int N;
  int *pid;
  int status, retpid;

  assert(argc == 2 && ((N = atoi(argv[1])) > 0));

  pid = (int*) malloc(N * sizeof(int));
  printf("All Reap Example Start\nN : %d\n", N);
  
  printf("Creating %d Children\n", N);
  for (int i = 0; i < N; i++) {
    if ((pid[i] = fork()) == 0) {
      exit(100 + i);
    }
  }
  
  int cnt = 0;
  while ((retpid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("Process %d is reaped. status: %d\n", retpid, WEXITSTATUS(status));
      cnt ++;
    }
  }

  printf("Total Reaped : %d\n", cnt); 
  return 0;
}

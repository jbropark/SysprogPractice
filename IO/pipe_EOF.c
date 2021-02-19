#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define WRITE 1
#define READ 0

int main(int argc, char *argv[]) {
  int fd[2];
  int pid;
  pipe(fd);

  if ((pid = fork()) == 0) {    // child
    close(fd[WRITE]);
    char c;
    int d;
    while(1) {
      d = read(fd[READ], &c, 1);
      printf("[CHILD] status : %d, character : %c\n", d, c);
      fflush(stdout);
      sleep(1);
    }

  } else {              // parents
    close(fd[READ]);
    
    for (int i = 5; i >= 0; i--) {
      printf("[PARENT] close in %d\n", i);
      sleep(1);
    }

    close(fd[WRITE]);

    sleep(4);
    kill(pid, SIGKILL);
    wait(NULL);
  }

  return 0;
}

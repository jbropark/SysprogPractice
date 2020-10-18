#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Test Start\n");
  
  int option = 0;
  int status = 0;

  printf("Test option : %d\n", option);
  int pid = fork();
  if (pid == 0) {
    printf("Child terminate in 3 seconds\n");
    sleep(3);
    printf("Child terminate\n");
    return 150;
  } else {
    printf("Parent wait start\n");
    waitpid(pid, &status, option);
    printf("wret: %d, ifexited: %d, status: %d\n", status, WIFEXITED(status), WEXITSTATUS(status));
    printf("after waitpid\n");
  }
}


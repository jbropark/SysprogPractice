#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pid_t pid;

  if (pipe(fd) < 0) return EXIT_FAILURE;

  if ((pid = fork()) > 0) {
    printf("Parent: sending message to child...\n");
    char write_msg[] = "Hello";

    close(fd[0]);
    for (int i = 0; i < strlen(write_msg); i++) {
      write(fd[1], write_msg + i, 1);
      sleep(1);
    }
    close(fd[1]);
    wait(NULL);

    printf("parent exits\n");
  } else {
    printf("Child: receving message from parent...\n");

    char c;

    close(fd[1]);
    while(1) {
      if (read(fd[0], &c, 1) > 0) {
        write(STDOUT_FILENO, &c, 1);
      } else {
        write(STDOUT_FILENO, "\n", 1);
        break;
      }
    }
    close(fd[0]);

    printf("Child exists\n");
  }
  return EXIT_SUCCESS;
}

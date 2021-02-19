#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signo) {
  printf("SIG NO is %d\n", signo);
  printf("CATCHED!\n");
}

int main(int argc, char *argv[], char *envp[])
{
  pid_t pid;
  
  if ((pid = fork()) == 0) {
    printf("Child start waiting...\n");
    signal(SIGCONT, signal_handler);
    //setpgid(0, 0);
    pause();
    printf("Signal Reached!\n");
    exit(0);
  } else {
    for (int i = 2; i > 0; i--) {
      printf("Wait %d seconds\n", i); 
      sleep(1);
    }
    printf("Send signal to %d\n", pid);
    kill(pid, SIGCONT); 
  }
}

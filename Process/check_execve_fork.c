#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  
  char *s[] = {"./getpid", "&", NULL};
  printf("Test Start\n");
  printf("The execve executing pid : %d", getpid());
  
  execve(s[0], s, envp);

}

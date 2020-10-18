#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {

  char *s[] = {"ls", "/bin", "-al", NULL};

  char *new[] = {"PATH=/bin", NULL};

  printf("Start Executing \n");

  printf("[old] PATH = %s\n", getenv("PATH"));

  //setenv("PATH", "/bin", 1);

  printf("[changed] PATH = %s\n", getenv("PATH"));

  printf("%s\n", envp[1]);

  int n = execve(s[0], s, envp);
  if (n)
    printf("ERROR!\n\n");
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  
  printf("arg num : %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argv[%2d]: %s\n", i, argv[i]);
  }
  int i = 0;
  for (int i = 0; envp[i] != NULL; i++) {
    printf("envp[%2d]: %s\n", i, envp[i]);
  }
}

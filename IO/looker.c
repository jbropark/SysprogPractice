#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  struct stat st; 
  stat(argv[1], &st);

  printf("IS USER READ? %d\n", S_ 
}

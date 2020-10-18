#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  
  struct stat st;
  while(1) {
    stat(argv[1], &st);
    printf("[show] size : %lu\n", st.st_size);
    sleep(3);
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]) {
  
  int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); 
  struct stat st;
  while(1) {
    write(fd, "a", 1);
    stat(argv[1], &st);
    printf("[changer] size : %lu\n", st.st_size);
    sleep(2);
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  

  if (fork() == 0) {
    int fd = open(argv[1], O_RDWR | O_APPEND, S_IRWXU); 
    int i = 0;
    char s[] = "0123456789";
    while (1) {
      sleep(1);
      write(1, "CHD : ", 6);
      write(fd, s + i % 10, 1);
      write(1, s + i % 10, 1);
      write(1, "\n", 1);
      i++;
    }
  } else {
    int fd = open(argv[1], O_RDWR | O_APPEND, S_IRWXU); 
    char c;
    while (1) {
      int d = read(fd, &c, 1);
      printf("PAR : %c suc : %d\n", c, d);
      sleep(1);
    }
  }
  return 0;
}

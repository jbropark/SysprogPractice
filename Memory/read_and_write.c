#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

  int fd = open(argv[1], O_RDWR, S_IRWXU);

  int suc = write(fd, "a", 1);
  printf("suc : %d\n", suc);

  char c;
  suc = read(fd, &c, 1);
  printf("suc : %d, char : %c\n", suc, c);
}

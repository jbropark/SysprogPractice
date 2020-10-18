#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
  char c1, c2, c3;
  int fd1 = open(argv[1], O_RDONLY, 0);
  int fd2 = open(argv[1], O_RDONLY, 0);
  int fd3 = open(argv[1], O_RDONLY, 0);
  printf("%d %d %d\n", fd1, fd2 ,fd3);
  dup2(fd2, fd1);
  read(fd1, &c1, 1);
  read(fd2, &c2, 1);
  printf("%d %d %d\n", fd1, fd2, fd3);
  printf("%c %c\n", c1, c2);
  return 0;
}

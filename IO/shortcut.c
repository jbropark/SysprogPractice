#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  char c;

  lseek(fd, 10, SEEK_SET);
  int d = read(fd, &c, 1);
  printf("%d %c\n", d, c);
  return 0;
}

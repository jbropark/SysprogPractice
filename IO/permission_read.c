#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  int fd, ret;
  errno = 0;
  fd = open(argv[1], O_RDWR, 0);
  printf("%s\n", strerror(errno));
  errno = 0;
  ret = write(fd, "a", 1);
  printf("ret : %d\n", ret);
  printf("%s\n", strerror(errno));
}

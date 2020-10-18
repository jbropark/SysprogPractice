#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
  write(fd, "ab", 2);
  return EXIT_SUCCESS;
}

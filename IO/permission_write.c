#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[], char* envp[]) {
  int fd;

  fd = open(argv[1], O_RDWR | O_CREAT, S_IROTH);

  write(fd, "asdf", 4);

  close(fd);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  printf("%s\n", argv[1]);
  errno = 0;
  DIR *dir = opendir(argv[1]);
  printf("%d\nerrno: %d\n", dir==NULL, errno);
  printf("%d %d", ENOENT, ENOTDIR);
  perror("ERROR");
  return 0;
}

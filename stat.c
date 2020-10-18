#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  struct stat info;
  errno = 0;
  printf("add: %s\n", argv[1]);
  int a = stat(argv[1], &info);
  perror(NULL);
  printf("%d\n", a);
  printf("%p\n", &info);
  printf("%d\n", info.st_mode);
  printf("Is dir? %d\n", S_ISDIR(info.st_mode));
  printf("Is File? %d\n", S_ISFIFO(info.st_mode));
  printf("Is Socket? %d\n", S_ISSOCK(info.st_mode));
  printf("Is REG? %d\n", S_ISREG(info.st_mode));
  return 0;
}

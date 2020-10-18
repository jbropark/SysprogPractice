#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

struct dirent *getNext(DIR *dir) {
  struct dirent *next;
  int ignore;
  do {
    next = readdir(dir);
    ignore = next && ((strcmp(next->d_name, ".") == 0) || (strcmp(next->d_name, "..") == 0));
  } while(next && ignore);
  return next;
}

size_t dirlen(DIR *dir) {
  struct dirent *next;
  size_t cnt = 0;
  long int start = telldir(dir);
  while((next = getNext(dir)) != NULL) {
    cnt++;
  }
  seekdir(dir, start);
  return cnt;
}

int main(int argc, char *argv[]) {
  DIR * dir = opendir(argv[1]);
  readdir(dir);
  readdir(dir);
  printf("%lu\n", dirlen(dir));
  return 0;
}

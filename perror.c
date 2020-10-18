#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  DIR *fp = opendir(argv[1]);
  perror(NULL);
  struct dirent *d = readdir(fp);
  perror(NULL);
}

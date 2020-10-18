#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]) {
  DIR* dir = opendir(argv[1]);
  struct dirent* dent;
  while((dent = readdir(dir)) != NULL) {
    char *name = dent -> d_name;
    char *sc = malloc(strlen(name) + 1);
    memcpy(sc, argv[1], strlen(argv[1]) + 1); 
    printf("sc : %p, size : %lu\n", sc, sizeof(sc));
    printf("%s ", name);
    printf("%s \n",strcat(strcat(sc, "/\0"), name));
    free(sc);
  }
  closedir(dir);
  return 0;
}

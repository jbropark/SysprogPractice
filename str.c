#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  printf("%s %s\n", argv[1], argv[2]);
  printf("%c\n", *(argv[1]));
  printf("%lu %lu\n", strlen(argv[1]), sizeof(argv[1]));
  printf("%s\n", strcat(argv[2], argv[1]));
  if(NULL) {
    printf("%d\n", 1);
  }
}

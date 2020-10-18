#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char a[20];
  strncpy(a, "asdf", 2);
  sprintf(a, "changed %d", 5);
  printf("%s\n", a);
  printf("12345\n");
  write(STDOUT_FILENO, "12\n345", 7);
}

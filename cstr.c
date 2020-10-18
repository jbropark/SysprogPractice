#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cstr(char *str, char *new_end)
{
  unsigned int slen = strlen(str);
  unsigned int nlen = strlen(new_end);
  str[slen - nlen] = '\0';
  strcat(str, new_end);
  return str;
}

int main(int argc, char *argv[]) {
  printf("%s\n", argv[1]);
  printf("%s\n", cstr(argv[1], "`-"));
  return 0;
}

#include <stdio.h>

enum test {
  A,
  B,
  C,
  D,
  E,
  F,
};

int main(int argc, char *argv[])
{
  enum test b;
  b = 4;
  printf("%d\n", b);
}

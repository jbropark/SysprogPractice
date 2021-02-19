#include <stdio.h>

extern void foo(void);

static int x = 0x01234567;
static int y = 0x89ABCDEF;

int main(void) {
  foo();
  printf("%p %p\n", &x, &y);
  printf("%x %x\n", x, y);
  return 0;
}

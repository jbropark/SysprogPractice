#include <stdio.h>

extern int not_ref;

int global = 0;

int *low = &global;

int *low2 = &global;

extern int minus(int a, int b);

int sum(int a, int b)
{
  return a + b + global + minus(a, b);
}

void local()
{
  static int a;
  a++;
  printf("%d %d %d\n", a, global, sum(a, global));
}

int main(int argc, char *argv[]) 
{
  int meaningless;
  printf("ml: %d, notref: %d\n", meaningless, not_ref);
  local();
  local();
  local();
  return 0;
}

#include <stdio.h>

int sum(int a, int b)
{
  return a + b;
}

int main(int argc, char *argv[])
{
  int (*inter)(int a, int b);
  inter = sum;
  printf("%d\n", inter(5, 9));
  
  return 0;
}

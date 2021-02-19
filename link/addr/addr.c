#include <stdio.h>
#include <stdlib.h>

int global = 4;

int sum(int a, int b)
{
  return a + b;
}

int main(int argc, char *argv[])
{
  int stack = 5;
  int *ptr = (int *) malloc(sizeof(int));

  printf("main   : %p\n"
         "sum    : %p\n"
         "global : %p\n"
         "stack  : %p\n"
         "heap   : %p\n", main, sum, &global, &stack, ptr);

  free(ptr);
}

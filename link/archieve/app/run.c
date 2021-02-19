#include <stdio.h>
#include "../vector.h"

int a[] = {1,2,3,4};

int b[] = {4,4,1,13};

int main(int argc, char *argv[])
{
  int z[4] = {0};

  addvec(a, b, z, 4);

  for (int i = 0; i < 4; i++) {
    printf("%d\n", z[i]);
  }
  return 0;
}


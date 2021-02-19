#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n = 5, m = 4;

  int **p = (int **) malloc(sizeof(int *) * n);
  p[0] = (int *) malloc(sizeof(int) * n * m);

  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + m;
  }

  free(p[0]);
  free(p);

  return 0;
}

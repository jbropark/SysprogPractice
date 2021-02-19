int multcnt = 0;

int multvec(int *x, int *y, int *z, int n)
{
  int i;

  multcnt++;

  for (int i = 0; i < n; i++) {
    z[i] = x[i] * y[i];
  }

  return n;
}

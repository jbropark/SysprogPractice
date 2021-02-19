int addcnt = 0;

int addvec(int *x, int *y, int *z, int n)
{
  int i;

  addcnt++;

  for (int i = 0; i < n; i++) {
    z[i] = x[i] + y[i];
  }

  return n;
}

#define zero 0

int sum(int *s, int n) 
{
  int i, a = zero;
  for (int i = zero; i < n; i++) {
    a += s[i];
  }
  return a;
}

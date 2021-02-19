# 1 "sum.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "sum.c"


int sum(int *s, int n)
{
  int i, a = 0;
  for (int i = 0; i < n; i++) {
    a += s[i];
  }
  return a;
}

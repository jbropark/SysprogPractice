#include <stdio.h>
#include <stdlib.h>

typedef struct __tuple {
  int a;
  int b;
  int c;
  int d;
} tuple;

void dump_tuple(tuple t)
{
  printf("(%d, %d, %d, %d)\n", t.a, t.b, t.c, t.d);
}

int main(int argc, char *argv[])
{
  tuple t;
  tuple c = {1,2,3,4};

  dump_tuple(t);
  dump_tuple(c);

  t = c;

  dump_tuple(t);
  dump_tuple(c);

}

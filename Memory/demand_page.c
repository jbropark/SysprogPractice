#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

double measure(int (*func)(), ...) {
  double time_spend;
  clock_t begin, end;
  va_list argp;

  begin = clock();
  func(argp);
  end = clock();
  va_end(argp);
  return (double) (end - begin) / CLOCKS_PER_SEC;
}

int hello(int n) {
  printf("print%d", n);
  return n;
}

int main(int argc, char *argv[]) {
  double time_spent;
  clock_t begin, end;
  int fd;
  char c;

  begin = clock();
  fd = open(argv[1], O_RDONLY, S_IRUSR);
  end = clock();
  printf("open : %lf\n", (double)(end - begin) / CLOCKS_PER_SEC); 

  begin = clock();
  read(fd, &c, 1);
  end = clock();
  printf("open : %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

  begin = clock();
  read(fd, &c, 1);
  end = clock();
  printf("second : %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

}

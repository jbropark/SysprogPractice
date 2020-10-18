#include <unistd.h>
#include <sys/syscall.h>

int main(int args, char *argv[]) {
  
  write(1, "hello\n", 6);
  _exit(0);
}


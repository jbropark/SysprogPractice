#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("%d\n", getpid());
  while(1){
    printf("my : %d, parent : %d\n", getpid(), getppid());
    sleep(5);
  }
}

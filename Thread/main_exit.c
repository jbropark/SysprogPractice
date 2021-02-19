#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *run(void *arg)
{
  int n = 10;
  pthread_t tid;

  tid = pthread_self();

  for (int i = 0; i < n; i++) {
    printf("[%lu] processing %d\n", tid, i + 1);
    sleep(1);
  }

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tid;

  pthread_create(&tid, NULL, run, NULL);

  printf("I leave for free~~\n");
  pthread_exit(NULL);
}

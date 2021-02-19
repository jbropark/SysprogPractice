#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10

void *hello(void *ptr)
{
  pthread_t tid;

  tid = pthread_self();
  printf("Hello World! This is %lu\n", tid);

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tid_list[N];
  for (int i = 0; i < N; i++) {
    pthread_create(tid_list + i, NULL, hello, NULL);
  }
  for (int i = 0; i < N; i++) pthread_join(tid_list[i], NULL);

  printf("Hello everyone!\n");

  return EXIT_SUCCESS;
}

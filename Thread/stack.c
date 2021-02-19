#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 10

void *stack(void *arg)
{
  int p;

  printf("[Pid %d] [Tid %lu] thread stack: %p\n", getpid(), pthread_self(), &p);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pid_t pid;
  pthread_t tid[N];

  pid = getpid();

  printf("[Pid %d] thread_stack: %p\n", pid, &pid);

  for (int i = 0; i < N; i++) {
    pthread_create(&tid[i], NULL, stack, NULL);
  }

  for (int i = 0; i < N; i++) {
    pthread_join(tid[i], NULL);
  }

  return 0;
}

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

#define N 2

void *thread_routine(void *arg)
{
  char buf;
  int fd = *(int *)arg;
  pid_t tid = gettid();

  while (read(fd, &buf, 1) > 0) {
    printf("[%d] read: %c\n", tid, buf);
    sleep(1);
  }

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Need file path as a argument.");
    exit(EXIT_FAILURE);
  }

  char *file = argv[1];
  pthread_t tid[N];
  int fd = open(file, O_RDONLY);

  for (int i = 0; i < N; i++) {
    pthread_create(&tid[i], NULL, thread_routine, &fd);
  }

  for (int i = 0; i < N; i++) {
    pthread_join(tid[i], NULL);
  }

  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct _pthread_condition {
  pthread_cond_t cond;
  pthread_mutex_t mutex;
} condition;

void *routine(void *arg)
{
  pthread_cond_t *cond;

  cond = arg;

  printf("Hello!\n");
  printf("Wait...\n");
  sleep(6);
  printf("Done!\n");

  pthread_cond_signal(cond);

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tid;
  condition cond;

  pthread_cond_init(&cond.cond, NULL);
  pthread_mutex_init(&cond.mutex, NULL);

  pthread_create(&tid, NULL, routine, &cond.cond);
  pthread_detach(tid);

  pthread_cond_wait(&cond.cond, &cond.mutex);

  printf("I got it!\n");

  return EXIT_SUCCESS;
}

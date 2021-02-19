#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *cancel(void *arg)
{
  pthread_t tid = *(pthread_t *)arg;
  sleep(5);

  pthread_cancel(tid);
  printf("Stop Noisy!\n");

  pthread_exit(NULL);
}

void *cry(void *arg)
{
  while (1) {
    printf("cry!!\n");
    sleep(1);
  }
  
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) 
{
  pthread_t tid_cry, tid_can;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  pthread_create(&tid_cry, NULL, cry, NULL);
  

  pthread_create(&tid_can, &attr, cancel, &tid_cry);
  pthread_attr_destroy(&attr);

  printf("Done here\n");
  pthread_join(tid_cry, NULL);
  
  printf("Now we're happy\n");

  return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
  sem_t sem;
  sem_init(&sem, 0, 1);

  sem_post(&sem);
  printf("post\n"); fflush(stdout);
  sem_post(&sem);
  printf("post\n"); fflush(stdout);
  sem_wait(&sem);
  printf("wait\n"); fflush(stdout);
  sem_wait(&sem);
  printf("wait\n"); fflush(stdout);
  sem_wait(&sem);
  printf("wait\n"); fflush(stdout);
  sem_wait(&sem);
  printf("wait\n"); fflush(stdout);
  


  return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int sum = 0;

void *counter(void *param) {
  int k;
  for (k = 0; k < 10000; k++) {
    // entry section
    sem_wait(&sem);

    // critical section
    sum++;

    // exit section
    sem_post(&sem);

    // remainder section
  }
  pthread_exit(0);
}

int main() {
  // 5개 thread
  pthread_t tid[5];
  // sem_init(&sem, 0, 1);
  int i;
  for (i = 0; i < 5; i++) {
    pthread_create(&tid[i], NULL, counter, NULL);
  }
  for (i = 0; i < 5; i++) {
    pthread_join(tid[i], NULL);
  }
  printf("sum = %d\n", sum);
  return 0;
}
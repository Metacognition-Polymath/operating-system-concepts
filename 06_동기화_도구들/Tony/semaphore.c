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
  pthread_t tid1, tid2;
  // sem_init(&sem, 0, 1);
  pthread_create(&tid1, NULL, counter, NULL);
  pthread_create(&tid2, NULL, counter, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("sum = %d\n", sum); // 20000이 출력되지 않고 19997 같이 근사값이 출력됨 -> sem_init(&sem, 0, 1);을 mac에서 지원하지 않음
  // sem_destroy(&sem);
  return 0;
}
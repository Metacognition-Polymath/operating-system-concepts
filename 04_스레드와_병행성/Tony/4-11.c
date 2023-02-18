#include <pthread.h>
#include <stdio.h>

#include <stdlib.h>

int sum; // this data is shared by the thread(s)
void *runner(void *param); // threads call this function

int main(int argc, char *argv[]) {
  pthread_t tid; // the thread identifier
  pthread_attr_t attr; // set of thread attributes

  // set the default attributes of the thread
  pthread_attr_init(&attr);

  // create the thread
  pthread_create(&tid, &attr, runner, argv[1]);

  // wait for the thread to exit - 여러개의 스레드를 기다린다면 for문을 사용해서 pthread_join을 여러번 호출하면 된다.
  pthread_join(tid, NULL);

  printf("sum = %d\n", sum);
}

// The thread will execute in this function
void *runner(void *param) {
  int i, upper = atoi(param);
  sum = 0;

  if (upper > 0) {
    for (i = 1; i <= upper; i++)
      sum += i;
  }

  pthread_exit(0);
}

// 실행 예시 : ./a.out 10
- CSP : Critical Section Problem
  - 임계영역 문제

## 6.3 Peterson's solution

- 3가지 조건을 만족한다
  - Mutual exclusion(상호 배제)
  - Progress(데드락)
  - Bounded waiting(기아)
- 그렇지만 제대로 동작하지 않을 때가 있다

## 6.4 Hardware support for synchronization

- 하드웨어 지원이 없으면 context switching이 발생해서 동기화가 되지 않는다

### 6.4.2 하드웨어 명령어(Hardware instructions)

- Atomicity

  - 원자성
  - 더 이상 쪼갤 수 없는 인터럽트 단위의 작업(CPU 클럭 단위)

- 예를 들면 test-and-set 같은 명령어를 만들면 이것을 실행 중일 땐 context switching이 되지 않는다

  - 이때 flag(lock)을 true로 만들고 나올 때 false로 만든다(상호 배제)

- Compare-and-swap
  - flag를 0이면 1로, 1이면 0으로

### 6.4.3 원자적 변수(Atomic variables)

- Java에서 지원하는 원자적 변수를 사용

  - AtomicBoolean

- 상호 배제만 고려해보자
  - mutex
  - semaphore
  - monitor

## Higher-level software tools to solve the CSP

- Higher-level software tools to solve the CSP
  - 상위레벨인 소프트웨어 레벨에서 임계영역 문제를 해결하는 방법은 없을까?
- Mutual exclusion
  - 상호 배제
  - 한 번에 하나의 프로세스만 임계영역에 들어갈 수 있다
- Mutex Locks은 가장 간단한 동기화(synchronization) 기법이다
  - 상호 배제만 고려한다
  - 데드락은 고려하지 않는다
  - 기아는 고려하지 않는다
  - 2개만 제어할 수 있다
- Semaphore
  - 제일 많이 쓰임
  - 상호 배제
  - 데드락
  - 기아
  - 여러 개 제어 가능(more robust)
- Monitor
  - overcomes the demerits of mutex and semaphore
    - mutex와 semaphore의 단점을 극복
  - Java에서 modify, wait, notify, notifyAll을 제공
    - Java에서는 monitor를 제공
- Liveness
  - Progress(데드락) 문제를 해결

## 6.5 Mutex Locks

- mutex : mutual exclusion
  - 상호 배제
  - to protect critical section and prevent race condition

```java
while (true) {
  // acquire lock
  // -> critical section

  // release lock

  // remainder section
}
```

- 뮤텍스 락을 위한 두 개의 함수와 한개의 변수
  - acquire(), release(), available
  - acquire() : 뮤텍스 락을 얻는 함수
  - release() : 뮤텍스 락을 해제하는 함수
  - available : 뮤텍스 락이 사용 가능한지를 나타내는 변수
- CPU 소모를 쓸데 없이 됨
  - busy waiting 때문
    - mutex lock의 가장 큰 적
- Spinlock(=busy waiting)
  - 뮤텍스 락을 얻을 때 무한 루프를 돌면서 기다리는 것
  - 유용할 때 : 코어가 여러개가 있다면 context switching이 발생하지 않는다 -> 빠르다
    - 멀티코어 시스템에선 오히려 선호될 때도 있다

```c
#include <stdio.h>
#include <pthread.h>
int sum = 0;
pthread_mutex_t mutex;
void *counter(void *param) {
  int k;
  for (k=0; k<10000; k++) {
    // entry section
    pthread_mutex_lock(&mutex);

    // critical section
    sum++;

    // exit section
    pthread_mutex_unlock(&mutex);

    // remainder section
  }
  pthread_exit(0);
}

int main() {
  pthread_t tid1, tid2;
  pthread_mutex_init(&mutex, NULL);
  pthread_create(&tid1, NULL, counter, NULL);
  pthread_create(&tid2, NULL, counter, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("sum = %d\n", sum);
  return 0;
}
```

## 6.6 Semaphores

- n개 짜리 프로세스
- Semaphores : 기차길의 신호 깃발

#### Defining the Semaphore

- an integer variable that, apart from initialization
  - 초기화를 제외하고 정수 변수
- is accessed only through two standard atomic operations
  - 두 가지 표준 원자적 연산을 통해서만 접근 가능
  - wait() : P()
    - P: Proberen(test) - 시도하다
  - signal() : V()
    - V: Verhogen(increase) - 증가시키다

#### Definition of wait() and signal()

```c
// S : 전역 변수
wait(S) {
  while (S <= 0) ; // busy waiting
  S--;
}

signal(S) {
  S++;
}
```

- 열쇠 꾸러미 => 목욕탕의 락커룸

- 초기 S = 1 : mutex lock

  - binary semaphore

- 초기 S = n (n>1) : n개의 프로세스가 동시에 접근 가능
  - counting semaphore

#### Using the semaphore to solve synchronization problems

- 세마포 사용법

#### 세마포 구현

- busy waiting 문제 발생
- busy waiting 해결
  - wait()를 실행(waiting queue에 들어가도록 함)
  - signal() : wakeup()
    - waiting queue에서 꺼내서 실행

```c
typedef struct {
  int value;
  struct queue *waiting_queue;
} semaphore;

void wait(semaphore *S) {
  S->value--;
  if (S->value < 0) {
    // add this process to S->list;
    sleep();
  }
}

void signal(semaphore *S) {
  S->value++;
  if (S->value <= 0) {
    // remove a process P from S->list;
    wakeup(P);
  }
}
```

#### 세마포어에서 정상적으로 동기화되지 않는 경우

- 각 세마포 -> race condition이 발생할 수 있다
  - 락커룸은 한개 인데 열쇠는 여러개 인 상황
- mac에서 sem_init이 deprecated 돼서 sem_open으로 바꿔줘야 한다
  - https://medium.com/helderco/semaphores-in-mac-os-x-fd7a7418e13b
  - https://stackoverflow.com/questions/1413785/sem-init-on-os-x

## 6.7 Monitors

#### The difficulty of using semaphores

- The semaphore is convenient and effective for synchronization.
  - 세마포어는 동기화에 편리하고 효과적이지만
- However, timing errors can happen.
  - 그러나, 타이밍 에러가 발생할 수 있다
    - 특정 시퀀스를 잘못쓰면 프로그래밍 에러가 발생할 수 있음

#### An illustrative example of semaphore's problem

- wait()와 signal()을 잘못 사용하면 문제가 발생할 수 있다
  - signal을 먼저 사용하고 wait을 사용하면 문제가 발생할 수 있다
  - wait만 두번
  - wait와 signal을 해줘야되는 위치에서 해주지 않는 경우

#### How to deal with these kinds of difficulties?

- 위와 같은 상황은 종종 일어날 수 있다
- 심플한 synchronization tool을 사용하자 !
  - monitor

#### Monitor

- an abstract data type
  - 추상 데이터 타입
- including a set of programmer-defined operations that are provided with mutual exclusion within the monitor
  - 프로그래머가 정의한 연산의 집합
  - 뮤텍스를 제공하는 모니터 내에서
- 쉽게 생각하면 java의 클래스
- declares the variables : 변수 선언

  - whose values define the state of an instance of that type : 변수에 정의된 값은 그 타입의 인스턴스의 상태를 정의한다
  - along with the bodies of function that operate on those variables : 변수를 조작하는 함수의 본문

- pseudo code : 그림 6.11 monitor의 의사 코드 구문
- monitor에 정의된 자료구조의 메서드를 사용하면 동기화 문제를 해결할 수 있다

#### Conditional Variables

- 모니터가 그 자체적으로 동기화 문제를 해결하기 부족하기 때문에
- `condition` 변수를 추가
  - 각 프로세스에 대한 wait queue를 분리

### Java Monitors

- Java provides a monitor-like
- 자바는 기본단위가 thread, thread 단위로 동기화
- 방법 2가지

  - synchronized
  - wait() and notify()

#### synchronized 키워드

- 임계 영역에 해당하는 코드 블록을 선언할 때 사용하는 자바 키워드
- 해당 코드 블록(임계 영역)에는 모니터락을 획득해야 진입 가능
- 메소드에 선언하면 메소드 코드 블록 전체가 임계 영역으로 지정됨
- 이때, 모니터락을 가진 객체 인스턴스는 this 객체 인스턴스이다

```java

// synchronized 객체 인스턴스
synchronized (object) {
  // critical section
}

// synchronized 메소드
public synchronized void method() {
  // critical section
}

```

```java
public class SynchExample {
  static class Counter {
    public static int count = 0;
    // public static void increment() {
    synchronized public static void increment()
    {
      count++;
    }
  }

  static class MyRunnable implements Runnable {
    @Override
    public void run() {
      for (int i = 0; i < 10000; i++) {
        Counter.increment();
      }
    }
  }

  public static void main(String[] args) throws InterruptedException {
    Thread[] threads = new Thread[5];
    for (int i = 0; i < threads.length; i++) {
      threads[i] = new Thread(new MyRunnable());
      threads[i].start();
    }
    for (int i = 0; i < threads.length; i++) {
      threads[i].join();
    }
    System.out.println(Counter.count);
  }
}

```

#### wait() and notify()

- 어떤 쓰레드가 어떤 객체의 wait() 메소드를 호출하면
  - 해당 객체의 모니터락을 획득하기 위해 대기 상태로 진입함
- 쓰레드가 어떤 객체의 notify() 메소드를 호출하면
  - 해당 객체 모니터에 대기중인 쓰레드 하나를 깨움
- notifyAll()
  - 해당 객체 모니터에 대기중인 모든 쓰레드를 깨움

## 6.8 Liveness

- Mutex, Semaphore, Monitor는 deadlock, starvation을 발생시킬 수 있다
- Liveness에선 deadlock과 starvation을 해결하기 위해 고안되었다
- Two situations that can lead to liveness failures
  - Deadlock
  - priority inversion : 우선순위 역전

### Deadlock

### priority inversion

- 우선순위 역전
- 높은 우선순위의 프로세스가 낮은 우선순위의 프로세스를 기다리는 경우
- 우선순위가 낮은 프로세스가 먼저 공유자원을 점유하고 있기 때문에 그 프로세스가 끝날 때까지 우선순위가 높은 프로세스는 기다려야 한다
- e.g. 삼형제 예시
  - 막내가 티비를 보고 있다(리모콘을 가지고 있음)
  - 둘째가 막내를 쫒아냄
  - 막내는 리모콘을 가진채로 쫒겨남
  - 첫째가 둘째를 쫒아냄
  - 첫째는 리모콘이 어디에 있는지 알 수 없기에 계속 대기해야 한다

#### 해결 : priority inheritance

- 공유자원을 가진채로 쫒겨나기(preemptive) 전에 우선순위가 높은 프로세스의 우선순위를 상속받아 동등한 입장에서 해당 공유자원을 release할 때 까지 기다린다

# 7. 동기화 예제

- 이번 장에서는 6장에서 제시된 도구를 몇 가지 고전적인 동기화 문제에 적용한다
- 또한 Linux, UNIX, Windows 운영체제에서 사용하는 동기화 기법을 살펴보고
- Java 및 POSIX 시스템의 API 세부사항을 설명한다

#### 이 장의 목표

- 유한 버퍼, readers-writers, 식사하는 철학자 동기화 문제에 대해 설명한다
- `프로세스 동기화 문제`를 해결하기 위해 `Linux 및 Windows에서 사용하는 특정 도구`를 설명한다
- 프로세스 동기화 문제를 해결하기 위해 POSIX 및 Java가 어떻게 사용될 수 있는지 설명한다
- POSIX 및 Java API를 사용하여 동기화 문제를 처리하는 해결책을 설계하고 개발한다

## 7.1 고전적인 동기화 문제들 (Classic Problems of Synchronization)

- 동기화 문제 해결의 예시를 살펴본다
  - 유한 버퍼
  - Readers-Writers
  - 식사하는 철학자
- 해결책을 제시할 때 세마포를 사용한다
  - 책에선 세마포를 사용하지만 실제 구현 시 이진 세마포 대신 mutex 락이 사용될 수 있다

### 7.1.1 유한 버퍼 문제(The Bounded Buffer Problem)

- 유한한 버퍼가 있을 때 생산자와 소비자가 동시에 접근할 때 발생하는 문제를 해결한다
- 예제의 동작 방식
  - 생산자가 소비자를 위해 꽉찬 버퍼를 생산해내고,
  - 소비자는 생산자를 위해 비어 있는 버퍼를 생산해낸다

```java
// pseudocode
int n;
semaphore mutex = 1;
semaphore empty = n;
semaphore full = 0;

// 생산자의 프로세스 구조
while (true) {
  // produce an item in next produced
  wait(empty); // 생산자는 empty 0이 될 때까지 기다린다
  wait(mutex); // 생산자는 mutex 1이 될 때까지 기다리다가 점유하면 0으로 만든다
  // add next produced to the buffer
  signal(mutex); // 생산자는 mutex 세마포를 해제한다(1로 만든다)
  signal(full); // 생산자는 full 세마포를 1씩 증가시킨다
}

// 소비자의 프로세스 구조
while (true) {
  wait(full); // 소비자는 full n이 될 때까지 기다린다
  wait(mutex); // 소비자는 mutex 1이 될 때까지 기다리다가 점유하면 0으로 만든다
  // remove an item from buffer to next_consumed
  signal(mutex); // 소비자는 mutex 세마포를 해제한다(1로 만든다)
  signal(empty); // 소비자는 empty 세마포를 1씩 감소시킨다
  // consume the item in next consumed
}
```

- 생산자나 소비자 중 어떤 스레드를 순서대로 하는 것은 아닌 것 같고 단지 공유 변수(세마포)를 올리고 내림으로써 전부 사용가능한지 다 사용했는지를 확인하는 것 같다

### 7.1.2 Readers-Writers 문제(The Readers-Writers Problem)

- readers : 읽기만 하는 스레드
- writers : 읽고 쓰는 스레드
- reader가 동시에 공유 데이터에 접근하더라도 문제가 없다
- 그러나 하나의 writer가 공유 데이터에 접근하고 있을 때 다른 writer 또는 reader가 접근하면 문제가 발생한다

#### first readers-writers problem

- reader와 writer의 우선순위가 같다
  - 문제점 : writer가 늦게 처리 된다 => writer가 starvation

#### second readers-writers problem

- writer가 우선순위가 높다
  - 문제점 : reader가 starvation

#### first readers-writers problem 예제

```java
// pseudocode
semaphore rw_mutex = 1; // writer, reader 공통
semaphore mutex = 1; // critical section 보호용 => reader의 수를 세기 위해 사용(read_count)
int read_count = 0; // reader의 수 => read_count가 0이면 writer가 접근 가능

// writer 프로세스의 구조
while (true) {
  wait (rw_mutex); // writer는 rw_mutex 1이 될 때까지 기다리다가 점유하면 0으로 만든다
  // writing is performed
  signal (rw_mutex); // writer는 rw_mutex 세마포를 해제한다(1로 만든다)
}

// reader 프로세스의 구조
while (true) {
  wait (mutex);
  read_count++;
  if (read_count == 1) {
    // read_count는 1보다 커질 수 있고 하나라도 있으면(read_count >= 1) writer는 접근할 수 없다
    wait (rw_mutex); // reader는 rw_mutex을 점유하게 된다(0으로 만든다)
  }
  signal (mutex);

  // reading is performed

  wait (mutex);
  read_count--; // reader가 끝나면 read_count를 1 감소시킨다
  if (read_count == 0) {
    signal (rw_mutex); // 읽는 중인 reader가 없으면 rw_mutex 세마포를 해제한다(1로 만든다)
  }
  signal (mutex);
}
```

- Reader-writer lock은 다음 상황에서 유용하다
  - 공유 데이터를 읽기만 하는 프로세스와 쓰기만 하는 스레드를 식별하기 쉬운 응용 프로그램
  - Writer 보다 reader의 개수가 많은 응용 프로그램
    - 일반적으로 reader-writer lock을 설정하는 데 드는 오버헤드가 세마포나 상호 배제 락을 설정할 때 보다 크다
    - 이 오버헤드는 동시에 여러 reader가 읽게 하여 병행성을 높임으로써 상쇄할 수 있다

### 7.1.3 식사하는 철학자 문제(The Dining Philosophers Problem)

- 5명의 철학자를 기준으로 양옆에 젓가락이 하나씩 있고
  - 젓가락을 두 개 모두 잡아야 식사를 할 수 있다
- 젓가락을 기준으로 양옆에 철학자가 한명씩(두명)이 있고
  - 젓가락 기준 양옆의 철학자는 해당 젓가락을 공유한다

#### 7.1.3.1 세마포 해결안(Semaphore Solution)

```c
while (true) {
  wait(chopstick[i]);
  wait(chopstick[(i+1) % 5]);
  // eat for a while
  signal(chopstick[i]);
  signal(chopstick[(i+1) % 5]);
  // think for a while
}
```

- 한 가지 간단한 해결책은 각 젓가락을 하나의 세마포로 표현하는 것이다
- 위 해결 책은 교착상태(deadlock)이 발생할 가능성이 있다
- 교착상태 해결안
  - 방법1. 4명의 철학자만 앉게 한다
  - 방법2. 한 철학자가 젓가락을 두 개를 모두 집을 수 있을 때만 젓가락을 집도록 허용한다
  - 방법3. 비대칭 해결안을 사용한다
    - 홀수 번호의 철학자는 먼저 왼쪽 젓가락을 집고 다음에 오른쪽 젓가락을 집는다
    - 짝수 번호의 철학자는 오른쪽 젓가락을 집고 다음에 왼쪽 젓가락을 집는다
  - 그러나 교착상태가 없는 해결해도 starvation까지 해결하진 못했다

#### 7.1.3.2 모니터 해결안(Monitor Solution)

- 식사하는 철학자 문제에 대한 교착상태가 없는 해결안과 모니터의 개념을 설명
- 철학자는 양쪽 젓가락 모두 얻을 수 있을 때만 젓가락을 집을 수 있다는 제한을 강제한다(교착상태 해결안의 방법1)

```c
monitor DiningPhilosophers {
  enum {THINKING, HUNGRY, EATING} state[5]; // 각 철학자의 상태
  condition self[5]; // 철학자의 인원수

  void pickup(int i) {
    state[i] = HUNGRY;
    test(i); // 철학자가 젓가락을 얻을 수 있는지 확인
    if (state[i] != EATING) {
      self[i].wait();
    }
  }

  void putdown(int i) {
    state[i] = THINKING;
    test((i+4) % 5);
    test((i+1) % 5);
  }

  /**
   * 철학자가 젓가락을 얻을 수 있는지 확인
   */
  void test(int i) {
    // 왼쪽 사람이 먹고 있지 않고
    // 해당 철학자는 배고픈 상태이고
    // 오른쪽도 먹고 있지 않은 조건
    if ((state[(i+4) % 5] != EATING) && (state[i] == HUNGRY) && (state[(i+1) % 5] != EATING)) {
      state[i] = EATING;
      self[i].signal();
    }
  }

  initialization_code() {
    for (int i = 0; i < 5; i++) {
      state[i] = THINKING;
    }
  }
}

```

- 교착 상태가 발생하지 않는 다는 것은 보장하지만
- 기아 상태(starvation)가 발생할 수 있다

## 7.2 커널 안에서의 동기화(Synchronization within the Kernel)

- Windows, Linux 운영체제에서 제공되는 동기화 기법을 설명한다
- 커널을 동기화하기 위한 서로 다른 접근법의 좋은 예를 보여주고
- 이들 시스템에서 제공하는 동기화 방법은 미묘하면서도 큰 차이를 보인다

### 7.2.1 Windows의 동기화(Synchronization in Windows)

### 7.2.2 Linux의 동기화(Synchronization in Linux)

## 7.3 POSIX 동기화(POSIX Synchronization)

## 7.4 Java에서의 동기화(Synchronization in Java)

## 7.5 대체 방안들(Alternative Approaches)

### 7.5.1 트랜잭션 메모리

### 7.5.2 OpenMP

### 7.5.3 함수형 프로그래밍 언어

## 7.6 요약(Summary)

- 프로세스 동기화의 고전적인 문제에는 유한 버퍼, reader-writer 및 식사 하는 철학자 문제가 포함된다
- 이러한 문제에 대한 해결안은 mutex 락, 세마포, 모니터 및 조건 변수를 포함하여 6장에서 제공된 도구를 사용하여 개발할 수 있다
- `Windows`는 `dispatcher 객체`와 `event를 사용`하여 `프로세스 동기화 도구`를 구현한다
- `Linux`는 `원자적 변수`, `스핀락` 및 `mutex 락`을 포함한 경쟁 조건을 방지하기 위해 다양한 접근 방식을 사용한다
- POSIX API는 mutex락, 세마포 및 조건 변수를 제공한다
  - POSIX는 두 가지 형태의 세마포(기명과 무명)를 제공한다
    - 기명 세마포 : 관련이 없는 여러 프로세스가 단순히 이름을 참조하여 동일한 이름의 세마포에 쉽게 접근할 수 있다
    - 무명 세마포 : 쉽게 공유할 수 없으며 공유 메모리 영역에 세마포를 배치해야 한다
- Java에는 동기화를 위한 풍부한 라이브러리와 API가 있다
  - 사용 가능한 도구에는 모니터(언어 레벨로 제공됨)와 재진입 락, 세마포어 및 조건 변수(API에서 지원)가 포함된다
- 임계 구역 문제를 해결하기 위한 대안으로는 트랜잭션 메모리, OpenMP 및 함수형 언어가 있다
  - 함수형 언어는 절차적 언어와 다른 프로그래밍 패러다임을 제공하므로 특히 흥미롭다
  - 절차적 언어와 달리 함수형 언어는 상태를 유지하지 않으므로 일반적으로 경쟁조건 및 임계구역의 영향을 받지 않는다

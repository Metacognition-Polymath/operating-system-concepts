인프런 강의 메모

# 7. 스레드의 이해

- 하나의 프로세스가 여러개의 스레드를 가질 수 있다.

- 프로그램 카운터 : 다음에 실행할 명령어의 주소를 가리키는 레지스터

- 스택 포인터 : 스택의 최상위 주소를 가리키는 레지스터

- A thread is a lightweight process. It is a sequence of instructions within a process that can be executed concurrently with other threads.

- 지금까지 pid -> tid가 cpu를 점유

### 멀티 스레딩의 장점

1. Responsiveness

- 사용자 인터페이스를 더욱 빠르게 응답시킬 수 있다.

2. Resource Sharing

- 스레드는 프로세스의 자원을 공유할 수 있다.
- shared memory를 만들지 않아도 data를 공유할 수 있다.

3. Economy

- 스레드는 프로세스의 자원을 공유하기 때문에 프로세스를 생성하는 것보다 더 적은 자원을 사용한다.
- 프로세스를 생성하는 것보다 경제적이다(자원을 공유하기 때문에)
- context switching이 빠르다.

4. Scalability

- 멀티 프로세스보다 멀티 스레드가 더 적은 자원을 사용하기 때문에 더 많은 스레드를 생성할 수 있다.

### Thread in Java

#### 자바에서 스레드를 사용하는 방법 3가지

1. Thread 클래스를 상속받는다.
   - public void run() 메소드를 오버라이딩 한다.
2. Runnable 인터페이스를 구현한다.

- Runnable interface를 구현한 클래스를 생성한다.

3. Callable 인터페이스를 구현한다.

# 8. 멀티스레딩

- Two types of threads

  - User threads
    - CPU의 코어를 넘나 들 수 없음
    - 사용자 모드에서 사용하는 스레드
  - Kernel threads
    - CPU 코어를 직접 제어
    - OS가 관리
    - 커널모드에서 사용하는 스레드

- 다중 스레드 모델

  - Many to one model
    - 여러개의 스레드가 하나의 코어를 사용
    - 스레드가 많아지면 성능이 떨어짐
  - Many to many model
    - 여러개의 스레드가 여러개의 코어를 사용
    - 스레드가 많아지면 성능이 향상
  - One to one model
    - 하나의 스레드가 하나의 코어를 사용
    - 스레드가 많아지면 성능이 향상

- 스레드 라이브러리

  - POSIX Pthreads
  - Java Threads
  - Windows Threads
  - 운영체제 종속적

- Pthreads
  - POSIX Threads
  - POSIX 표준에 따라 만들어진 스레드 라이브러리
  - POSIX 표준은 유닉스 계열의 운영체제에서 사용하는 표준
  - POSIX 표준을 따르는 운영체제에서는 Pthreads를 사용할 수 있다.

## 4.5 스레딩을 개발자가 아닌 라이브러리에서 알아서 관리

- Thread Pools
- Fork & Join
- Open MP
- Grand Central Dispatch(GCD)
  - developed by Apple for its macOS and iOS operating systems

### OpenMP

- identifies parallel regions as blocks of code that may in parallel.

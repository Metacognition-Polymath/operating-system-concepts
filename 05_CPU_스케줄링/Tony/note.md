멀티 프로그래밍

- 멀티 태스킹

concurrent 하게 실행

CPU가 속도가 굉장히 빨라서 놀고 있음

시분할(time sharing)을 해서 CPU를 여러개의 프로세스에게 나눠줌

- CPU 스케줄링이 필요

CPU 버스트(running) -> I/O 버스트(waiting) -> CPU 버스트 -> I/O 버스트 -> ...

CPU 버스트 빈도보다 I/O 버스트 빈도가 높은 프로세스들이 더 많음

#### CPU 스케줄러

- CPU의 우선순위를 어떻게 결정할 것인가?

#### 선점형(Preemptive) vs. 비선점형(Non-Preemptive)

- 선점형(Preemptive) : 쫒아냄
- 비선점형(Non-Preemptive) : 자발적으로 나오게 기다림

#### Decision making for CPU scheduling

1. running -> waiting
2. running -> ready
3. waiting -> ready
4. process terminates

- 1, 4는 non-preemptive : 비선점형 - 자발적으로 나옴
- 2, 3은 preemptive : 선점형 - 쫒아냄

현대적인 OS는 2, 3 모두 preemptive

#### dispatcher

- CPU 코어의 컨트롤을 넘겨주는 것
- 컨텍스트 스위칭을 하는 모듈이 dispatcher이다
- 하는 일

  - 컨텍스트 스위칭
  - 유저 모드로 바꿈
  - 유저 프로그램을 재개

- dispatcher는 매우 빨라야 함
- dispatch latency : dispatcher가 일을 하는데 걸리는 시간

### 5.2 Scheduling Criteria

- 스케줄링의 기준(목표)
- CPU utilization
- Throughput : 완료되는 프로세스 수
- Turnaround time : 프로세스가 시작되고 종료되는데 걸리는 시간
- Waiting time 최소화 : 프로세스가 ready queue에 있었던 시간
  - 이것을 만족 시키면 위 모든 것을 만족
- Response time : 프로세스가 요청을 보내고 응답을 받는데 걸리는 시간
  - UI가 중요한 프로그램에 적합(게임)

### 5.3 CPU Scheduling Algorithms

- CPU Scheduling Problem
  - ready queue에 있는 프로세스들 중에서 어느 프로세스에 CPU를 할당해 줄 것인가를 결정하는 것
- The solution for the scheduling problem
  - FCFS : First Come First Served
    - ready queue에 있는 프로세스들 중에서 가장 먼저 도착한 프로세스에게 CPU를 할당
    - 아주 초창기 운영체제에서 사용(요즘엔 아무도 안씀)
  - SJF : Shortest Job First(SRTF : Shortest Remaining Time First)
    - 짧은 잡(프로세스)을 먼저 실행
    - SRTF : 남은 시간이 짧은 것을 먼저 실행
    - minimum waiting time
  - RR : Round-Robin
    - 시분할(Time sharing) 시스템에서 사용
    - 쪼개진 시간 단위로 프로세스를 실행
    - 요즘 대부분의 OS에서 사용
  - Priority-based
    - 우선순위를 부여해서 우선순위가 높은 프로세스에게 CPU를 할당
    - Round-Robin 과 같이 사용 됨
  - MLQ : Multi-Level Queue
    - 어떤 경우엔 어떤 알고리즘, 어떤 경우엔 어떤 알고리즘을 사용
  - MLFQ : Multi-Level Feedback Queue
    - 멀티레벨에 피드백을 먹여서 우선순위를 결정
    - 현대적인 스케줄러

# Chapter 5. CPU Scheduling part2

### SJF(Shortest Job First) Scheduling

- SJF을 구현할 수 있는가?

  - next CPU burst time을 알 수 없음

- approximate the SJF scheduling

  - predict(예측) the next CPU burst time
    - 과거를 보면 미래를 알 수 있다
    - 과거에 CPU를 많이쓰던 프로세스가 미래에도 CPU를 많이 쓸 것이다

- exponential average(지수적 평균)으로 구하자

  - 최근에 많이 썼다면 최근 것을 더 가중치를 둠

- 이론적으로 optimal 이다

- preemptive 또는 non-preemptive 모두 가능
  - preemtive가 더 좋다

### SRTF Scheduling ~= SJF Scheduling

- Shortest-Remaining-Time-First : Preemptive SJF

- Non-preemptive

## RR(Round-Robin) Scheduling

- 빙글 빙글 돈다
- preemptive FCFS(First come first served) with a time quantum(시간 단위)
- time quantum이 끝나면 ready queue의 맨 뒤로 간다
  - ready queue는 circular queue
- 아주 작은 시간단위를 부여
  - 보통 10ms ~ 100ms
- 만약 CPU burst time이 time quantum보다 작다면 자발적으로 빠져나옴
- round robin은 요즘 현대 OS 반드시 적용된다고 봐도 됨

- time quantum이 너무 크면 FCFS와 같아짐
- time quantum이 너무 작으면 overhead가 커짐(컨텍스트 스위칭이 너무 많이 일어남)
- time quantum을 어떻게 설정하느냐에 따라 OS 성능이 달라질 수 있다

## Priority-base Scheduling

- 우선순위를 부여해서 우선순위가 높은 프로세스에게 CPU를 할당
- SJF가 priority-based scheduling의 한 종류와 같다
  - priority : 1 / CPU burst time(cpu burst가 작을수록 우선순위가 높음)
- Priority scheduling 도 preemptive, non-preemptive 모두 가능
  - preemptive가 더 좋다
  - preemptive는 SRTF
  - non-preemptive는 SJF

## starvation problem

- 우선순위가 낮은 프로세스가 계속 CPU를 못받아서 끝나지 않는다
- 스케줄러입장에서 이것을 해결하는 방법
  - aging : (나이를 줘서)우선순위를 점점 높여준다

## combine RR and Priority Scheduling

- 높은 우선순위를 가진 프로세스가 먼저 실행되고
- 높은 우선순위를 가진 프로세스가 없다면 RR을 사용한다

## MLQ(Multi-Level Queue)

- 실전에선 간단하지만은 않다(변수가 많음)
- 여러개의 queue를 만들어서 우선순위에 따라서 queue를 나눈다
- e.g.
  - 게임 중 전화, 메시지가 왔을 때 게임을 멈추고 전화를 받는다
  - 전화의 우선순위가 제일 높음
- 큐를 여러개 두고 각 큐마다 우선순위가 다름
  - e.g.
    - (우선순위 최상위) 1번 큐 : real-time process
    - 2번 큐 : system process
    - 3번 큐 : interactive process(U/I)
    - (우선순위가 제일 낮은) 4번 큐 : batch process

## MLFQ(Multi-Level Feedback Queue)

- MLQ에 피드백을 먹여서 우선순위를 결정

## 5.4 Thread Scheduling

- 현대적 OS에선 process가 아닌 thread를 스케줄링 한다(thread를 지원하기 때문)
- kernel thread ~= CPU scheduling

## 5.6 Real-time operating system

- 실시간 운영체제
  - 실시간? 주어진 지간 내에 task를 완료할 수 있어야 함

### soft realtime vs. hard realtime

- soft realtime

  - critical real-time process가 반드시 그 시간안에 끝나진 않지만
  - critical process가 non-critical한 프로세스보다 먼저 실행되는 것을 보장
  - 빨리 처리는 하지만 중요하지 않는 것으 보장되지 않을 수 있다(전화에서 중간에 목소리 중간이 잘 들리지 않아도 알아 들을 수 있는 것과 같은 느낌)

- Hard realtime

  - e.g. 로켓
    - 아주 미세한 오차도 안됨
  - 어떤 task가 반드시 deadline안에 실행 되는 것

- 공통
  - 우선순위를 기반으로 함

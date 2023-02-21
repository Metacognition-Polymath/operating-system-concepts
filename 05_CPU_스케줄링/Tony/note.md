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

- 1, 4는 non-preemptive
- 2, 3은 preemptive

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

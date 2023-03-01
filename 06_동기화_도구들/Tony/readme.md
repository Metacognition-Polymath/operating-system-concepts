# Part 3. 프로세스 동기화(Process Synchronization)

- 시스템은 일반적으로 병행하게 또는 병렬로 실행되는 수백 개 또는 수천 개의 스레드로 구성된다
- 스레드는 종종 사용장 데이터를 공유한다
- 한편, 운영체제는 다양한 자료구조를 지속적으로 업데이트하여 여러 스레드를 지원한다
- 공유 데이터에 대한 액세스가 제어되지 않으면 `갱쟁 조건`이 존재하여 `데이터 값이 손상`될 수 있다
- 프로세스 동기화는 갱정 조건을 피하고자 공유 데이터에 대한 `액세스를 제어하는 도구`를 사용한다
- 이러한 도구를 잘못 사용하면 교착 상태를 포함한 시스템 성능이 저하될 수 있으므로 주의해서 사용해야 한다

# 6. 동기화 도구들(Synchronization Tools)

- 협력적 프로세스 : 시스템 내에서 실행 중인 다른 프로세스의 실행에 영향을 주거나 영향을 받는 프로세스
  - 논리 주소 공간(코드 및 데이터)을 직접 공유하거나 공유 메모리 또는 메시지 전달을 통해서만 데이터를 공유할 수 있다
- 그러나 공유데이터를 동시에 접근하면 데이터의 일관성을 망칠 수 있다
- 이 장에서는 놀리 주소 공간을 공유하는 협력적 프로세스의 질서 있는 실행을 보장하여, 이를 통해 데이터의 일관성을 유지하는 다양한 메커니즘을 논의한다

#### 이 장의 목표

- `임계구역 문제`를 설명하고 `경쟁 조건`을 설명한다
- `메모리 장벽`, `compare-and-swap 연산` 및 `원자적 변수`를 사용하여 `임계구역 문제에 대한 하드웨어 해결책`을 설명한다
- `Mutex 락`, `세마포`, `모니터` 및 `조건 변수`를 사용하여 `임계구역 문제를 해결하는 방법`을 보인다
- 적은, 중간 및 심한 경쟁 시나리오에서 임계구역 문제를 해결하는 도구를 평가한다

## 6.1 배경

#### count의 현재 값은 5이고 생산자와 소비자는 count++과 count--를 병행하게 실행한다고 가정

- T0: producer execute register1 = count {register = 5}
- T1: producer execute register1 = register1 + 1 {register = 6}
- T2: consumer execute register2 = count {register = 5}
- T3: consumer execute register2 = register2 - 1 {register = 4}
- T4: producer execute count = register1 {count = 6}
- T5: consumer execute count = register2 {count = 4}

#### Java로 동기화 문제 보기

## 6.2 임계구역 문제(The Critical-Section Problem)

## 6.3 Peterson의 해결안(Peterson's Solution)

## 6.4 동기화를 위한 하드웨어 지원(Hardware support for Synchronization)

### 6.4.1 메모리 장벽(Memory Barriers)

### 6.4.2 하드웨어 명령어(Hardware Instructions)

### 6.4.3 원자적 변수(Atomic Variables)

## 6.5 뮤텍스 락(Mutex Locks)

- Mutex lock = mutual(상호간의) exclusion(제외) lock

## 6.6 세마포(Semaphores)

### 6.6.1 세마포 사용법(Semaphore Usage)

### 6.6.2 세마포 구현(Semaphore Implementation)

## 6.7 모니터(Monitors)

### 6.7.1 모니터 사용법(Monitor Usage)

### 6.7.2 세마포를 이용한 모니터의 구현(Implementing a Monitor using Semaphores)

### 6.7.3 모니터 내에서 프로세스 수행 재개(Resuming Processes within a Monitor)

## 6.8 라이브니스(Liveness)

### 6.8.1 교착 상태(Deadlock)

### 6.8.2 우선순위 역전(Priority Inversion)

## 6.9 평가(Evaluation)

## 6.10 요약(Summary)

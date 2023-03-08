# 7. 동기화 예제

- 이 번장에서는 6장에서 제시된 도구를 몇 가지 고전적인 동기화 문제에 적용한다
- 또한 Linux, UNIX, Windows 운영체제에서 사용하는 동기화 기법을 살펴보고
- Java 및 POSIX 시스템의 API 세부사항을 설명한다

#### 이 장의 목표

- 유한 버퍼, readers-writers, 식사하는 철학자 동기화 문제에 대해 설명한다
- `프로세스 동기화 문제`를 해결하기 위해 `Linux 및 Windows에서 사용하는 특정 도구`를 설명한다
- 프로세스 동기화 문제를 해결하기 위해 POSIX 및 Java가 어떻게 사용될 수 있는지 설명한다
- POSIX 및 Java API를 사용하여 동기화 문제를 처리하는 해결책을 설계하고 개발한다

## 7.1 고전적인 동기화 문제들 (Classic Problems of Synchronization)

### 7.1.1 유한 버퍼 문제(The Bounded Buffer Problem)

### 7.1.2 Readers-Writers 문제(The Readers-Writers Problem)

### 7.1.3 식사하는 철학자 문제(The Dining Philosophers Problem)

## 7.2 커널 안에서의 동기화(Synchronization within the Kernel)

- Windows, Linux 운영체제에서 제공되는 동기화 기법을 설명한다
- 커널을 동기화하기 위한 서로 다른 접근법의 좋은 예를 보여주고
- 이들 시스템에서 제공하는 동기화 방법은 미묘하면서도 큰 차이를 보인다

### 7.2.1 Windows의 동기화(Synchronization in Windows)

### 7.2.2 Linux의 동기화(Synchronization in Linux)

## 7.3 POSIX 동기화(POSIX Synchronization)

## 7.4 Java에서의 동기화(Synchronization in Java)

## 7.5 대체 방안들(Alternative Approaches)

## 7.6 요약(Summary)

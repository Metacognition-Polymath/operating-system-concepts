# 스토리지와 입출력

- 인프런 강의를 듣고 정리한 내용입니다.
- https://www.inflearn.com/course/lecture?courseSlug=%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%EA%B3%B5%EB%A3%A1%EC%B1%85-%EC%A0%84%EA%B3%B5%EA%B0%95%EC%9D%98&unitId=65292

# 11. Mass-Storage structure

## Mass-Storage

- 2차 저장장치
- usually, HDD(Hard Disk Drive), NVM(Non-Volatile Memory)
- sometimes, magnetic tape, optical disk, or cloud storage
  - using the structure of RAID systems

## Hard Disk Drive

- spindle, tracks, sectors, cylinders, arm assembly

### HDD scheduling

- seek time을 줄이는 것을 가장 큰 목표로 한다
- disk bandwidth(대역폭)
  - disk가 한 번에 읽을 수 있는 양

### FIFO scheduling

### Scan scheduling

### C-Scan scheduling

- circular scan scheduling
- 한 방향으로만 헤드를 움직이자
- 원형 리스트 처럼 다루자

### Boot Block

- ROM : Read Only Memory

### RAID: Redundant Array of Independent Disks

- 여러 개의 디스크를 하나의 디스크처럼 사용하는 기술

- Redundancy : Improvement of Reliability
  - 중복으로 신뢰성을 높이자
- 가장 쉬운 방법 : mirroring
  - 대구의 데이터 센터를 부산에 복제
- Parallelism : Improvement of Performance
  - 병렬로 성능을 높이자

## RAID Levels

- mirroring: highly reliable, however, too expensive
- striping : highly efficient, however, not related reliable
- How about parity?
  - parity bit
    - 짝수 : 1
    - 홀수 : 0
    - 한 비트를 더 써서 그 중에서 홀 수개가 깨진 것을 확인할 수 있다
- parity bit -> check sum -> CRC
- cost-performance trade-off
  - 비용이 많이 들지만 퍼포먼스가 좋은 것 또는 그 반대

### RAID 0

- 아무것도 적용 안한 것

### RAID 1

- mirroring

### RAID 4

- striping with parity

### RAID 5

- striping with distributed parity

### RAID 6

- parity bit + queue

### Multidimensional RAID 6

- 다차원 레이드

# 12. I/O System

- 컴퓨터의 두 가지 주요 업무 : 계산(computing), 입출력(I/O)
- bus : 컴퓨터와 입출력 장치를 연결하는 통로
- controller : 입출력 장치를 제어하는 장치
  - bus에 각 장치들이 여러개 달려있고 각 장치마다 컨트롤러 있음
- Memory-Mapped I/O

## Three types of I/O

- polling: busy waiting
  - CPU가 계속해서 장치의 상태를 확인
- interrupt: asynchronous
  - 장치가 CPU에게 알려줌
- DMA: direct memory access
  - CPU가 아닌 DMA controller가 메모리에 직접 접근

## Blocking I/O vs. Non-Blocking I/O

- Blocking I/O
  - I/O가 끝날 때까지 기다림
  - I/O가 끝나면 CPU에게 알려줌
- Non-Blocking I/O
  - I/O가 끝나지 않았으면 CPU에게 알려주지 않음
  - I/O가 끝나면 CPU에게 알려줌
- The difference between Non-Blocking and Asynchronous system call
  - Non-Blocking read() call
    - returns immediately with whatever data are available
    - the full number of bytes requested, fewer, or none at all
      - 많이보내든 안보내든 조금만 보내든 상관 없음
  - Asynchronous read() call
    - request a transfer that will be performed in its entirety
    - but will complete at some future time
    - 요청만 하고 바로 자기 할일을 함

# 13. File System

- 로지컬하게 스토리지에 저장된 파일(data and programs)들을 관리하는 것
- 파일 시스템은 크게 두 개가 있음
  - 파일, 폴더(디렉토리)를 관리하는 것

### Access Methods

- sequential access
  - 파일의 처음부터 끝까지 순차적으로 접근
  - 테이프 같은 것
- random access
  - 파일의 임의의 위치에 접근
  - 요즘 대부분

### Directory Structure

# 14. File System Implementation

## 9.1 Background

- A process is a program in execution

  - to say, a set of instructions kept in a main memory

- A memory consists of
  - a large array of bytes, each with its own address
    - 메모리엔 주소가 있다
  - CPU는 메모리 주소에 있는 인스트럭션을 가져와서 실행
- 메모리 주소 공간을 따로 따로 관리할 수 있어야 함
- base register와 limit register를 사용하여 메모리 주소 공간을 관리
  - base register: 메모리 주소 공간의 시작 주소
  - limit register: 메모리 주소 공간의 크기
- 정해진 메모리 영역(base ~ base + limit)을 넘어가면 segmentation fault가 발생

### 9.1.2 Address Binding

- 프로그램에서 주소를 다루는 방식은 단계별로 다 다르다
  - source code
    - `int a` -> 컴파일러가 알아서 변수의 메모리 주소를 할당
  - 컴파일 된 파일
    - code.out
    - code.exe : 메모리의 몇 번지에 올라가는지 알 수 없음
      - 내가 그의 이름을 불러주기 전에는 그는 다만 하나의 몸짓에 지나지 않았다. 내가 그의 이름을 불러주었을 때, 그는 나에게로 와서 꽃이 되었다.(김춘수 - 꽃)
      - 내가 그 파일을 실행시키기 전에는 그것은 다만 하나의 바이너리에 지나지 않았다. 내가 그 파일을 실행시켰을 때, 그것은 메모리에 올라가서 프로세스가 되었다.

### 9.1.5 동적 연결 및 공유 라이브러리(Dynamic Linking and Shared Libraries)

- 정적 연결(Static Linking)
  - 컴파일 시에 라이브러리를 포함시키는 방식
  - 라이브러리가 변경되면 다시 컴파일 해야 함
  - loader가 전부 링킹을 해버림
- 동적 연결(Dynamic Linking)
  - 실행 시에 라이브러리를 포함시키는 방식
  - 라이브러리가 변경되어도 다시 컴파일 할 필요가 없음
  - 링킹을 실행 시 까지 연기시키고 실행 중에 DLL 파일을 access에서 링킹
- 동적 연결 파일 예시
  - windows : .dll
  - linux : .so

## 9.2 Contiguous Memory Allocation : 연속 메모리 할당

- contiguous : 연속, 접촉하는
- 여러개의 프로세스는 동시에 메모리에 올라갈 수 있다
- 사용 가능한 메모리를 어떻게 할당할 것인가?

### 9.2.2 메모리 할당(Memory allocation)

- size가 n인 free hole에서 어떻게 메모리를 할당할 것인가?
  - first fit
    - 가장 먼저 찾은 free hole에 할당
  - best fit
    - 가장 작은 free hole에 할당
      - 메모리를 작은 순으로 정렬해서 들어갈 수 있는 곳에 넣는다 -> 연습문제 9.13
  - worst fit
    - 가장 큰 free hole에 할당

### 9.2.3 Fragmentation

- 외부 단편화(exterior fragmentation)
  - 프로세스 단위로 단편화 <- 연속 메모리 할당(Contiguous Memory Allocation)
  - 짜투리 공간이 남는다
- 내부 단편화(interior fragmentation)
  - 똑같은 크기로 미리 잘라 놓는다 <- 페이징(Paging)

### Segmentation

- 연습문제 10.12
- 연속 메모리 할당에서 내부 단편화 시 종류별로 쪼개는 방법

# 20번째 강의 페이징과 스와핑

## 9.3 페이징(Paging)

### 9.3.1 기본 방법(Basic method)

- 물리적으로 고정된 사이즈 블럭(frame)으로 나누고 논리 메모리와 매핑
- e.g. 4KB frame
  - 0 ~ 4095
  - 4096 ~ 8191
  - 8192 ~ 12287
  - ...
- logical address와 physical address와 실제 매핑은 분리, OS가 관리
- page number, page offset으로 나누어서 관리
  - page number: 페이지 번호
  - page offset: 페이지 내에서의 offset
  - e.g.
    - 2번 페이지의 34번째 주소 : logical address
    - 2번 페이지의 34번째 주소를 찾으려면
      - 2번 페이지의 시작 주소를 찾아서 34를 더하면 된다
      - 2번 페이지의 시작 주소 = 2 \* 4096
      - 2번 페이지의 시작 주소 + 34 = 2 \* 4096 + 34
- page number는 page table에 저장

```ts
enum LogicalMemory = {
  page0,
  page1,
  page2,
  page3,
}

const pageTable = {
  page0: 1,
  page1: 4,
  page2: 3,
  page3: 7,
}

const frameNumber = {
  0: undefined,
  1: pageTable.page0,
  2: undefined,
  3: pageTable.page2,
  4: pageTable.page1,
  5: undefined,
  6: undefined,
  7: pageTable.page3,
}

```

#### Page size(frame size)는 어떻게 결정할 것인가?

- hardware에 따라 다름
- 페이지 사이즈는 반드시 2의 배수이어야 함(A power of 2)
- logical address space가 2^m(e.g. 2^10) 이고 page size가 2^n(e.g. 2^2)이면
  - page number는 m-n bits
  - page offset은 n bits

### 9.3.2 하드웨어 지원(Hardware support)

- PTBR(Page Table Base Register) : page table의 시작 주소를 저장
  - CPU안에 있는 레지스터
  - 2번 메모리에 접근해야 된다는 단점이 있다
- TLB(Translation Lookaside Buffer) : page table의 일부를 저장

### 9.3.3 Protection(보호)

- protection bit를 사용하여 보호
  - 페이지 테이블에 대한 접근이 valid한지 invalid한지를 나타내는 bit

## 9.4 페이지 테이블의 구조

- 너무 커진 페이지 테이블을 어떻게 관리할 것인가
  - Hierarchical paging(계층적 페이징) : 계층적으로 관리하자
  - Hashed paging(해시 페이징) : 페이지 테이블을 해싱하자
  - Inverted page table(역 페이지 테이블) : 페이지 테이블을 역으로 주소관리

### 9.4.1 계층적 페이징(Hierarchical paging)

- 페이지 테이블을 한번 더 두어서 관리(2 level page table)

### 9.4.2 해시 페이징(Hashed paging)

- O(1)에 찾을 수 있다 - hash function을 통해서

### 9.4.3 Inverted page table

- 지금까진 logical을 쪼개서 physical을 찾았다
- pid를 추가해줌

## 9.5 Swapping

- 나중에 디멘드 페이징을 배우기 위해서 알아야 함
- 실제 메모리보다 더 큰 로지컬 메모리를 사용할 수 있다

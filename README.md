# 운영체제(Operation System Concepts) 10th Edition

- 저자 : Abraham Silberschatz, Peter B. Galvin, Greg Gagne
- 출판사 : Wiley
- 발행처 : 퍼스트 북(First Book)

![책_운영체제](./images/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C%EC%B1%85%ED%91%9C%EC%A7%80.jpeg)

- OS 책 홈페이지 : https://www.os-book.com/OS10/
- 연습문제 정답
  - https://www.os-book.com/OS10/practice-exercises/index-solu.html

## 스터디

- 시간

  - 매주 토요일 오후 9시

- 장소

  - [게더타운](https://app.gather.town/app/zF6wrPJUcYkDEXde/metacognition)

- 발표 순서
  - Tony -> 만보 -> 노베 -> 린 -> 무지

## 서문

- 운영체제는 모든 컴퓨터 시스템의 필수적인 부분이다
- 이 책에서 다루고 있는 기본 개념과 알고리즘들은 공개 소스 운영체제와 사용 운영체제에서 자주 사용되는 것들에 기반을 두고 선정하였다
- Linux, Microsoft Windows, Apple macOS, Solaris, Android, iOS의 실례도 제시한다

### 이 책의 내용

- 이 교재는 10개의 주요 부분으로 구성되어 있다

#### 1. 개관

- 1장과 2장은 운영체제란 무엇인지, 어떤 일을 하는지, 어떻게 설계되고 구축되는지를 설명한다
- 운영체제의 공통 특징이 무엇인지, 운영체제가 사용자를 위해 무엇을 하는지를 설명한다
- 이 장들은 자세한 내부 알고리즘 공부없이 운영체제가 무엇인지 배우기를 원하는 전공 지식수준이 낮은 학생이나 독자에 적합하다

#### 2. 프로세스 관리

- 3장부터 5장까지는 현대의 운영체제의 심장부로서 프로세스 개념과 병행성을 다룬다
- `프로세스`는 시스템의 작업 단위로서 시스템은 `병행하게` 실행되는 프로세스의 집합으로 구성되는데
  - 일부는 시스템 코드를 실행하고
  - 나머지는 사용자 코드를 실행한다
- 이 장들은 프로세스 스케줄링, 프로세스 간 통신을 위한 방법들을 제시한다
- 또한 이 장들에서는 스레드에 관한 논의뿐 아니라 다중 코어 시스템과 병령 프로그래밍과 관련된 주제에 대한 검토가 이루어진다

#### 3. 프로세스 동기화

- 6장부터 8장까지는 프로세스 동기화 및 교착 상태 처리 방법에 대해 설명한다
- 프로세스 동기화의 적용 범위를 늘렸기 때문에 이전 5장(프로세스 동기화)를 6장 동기화 도구 및 7장 동기화 예제의 두 장으로 나누었다

#### 4. 메모리 관리

- 9장과 10장은 프로세스가 실행되는 동안 메인 메모리를 어떻게 관리하는가에 대한 문제를 다룬다
- CPU의 효율적인 활용과 사용자에게 빠른 응답 시간을 보장하기 위해 컴퓨터는 한순간에 많은 프로세스를 메모리에 유지해야 하는 것이 필수적이다
- 메모리 관리에 관한 다양한 접근 방법을 반영하는 많은 종류의 메모리 관리 기법들이 존재하며 특정 알고리즘의 유효성은 상황에 따라 달라진다

#### 5. 저장장치 관리

- 11장과 12장은 현대 운영체제가 대용량 저장장치와 입출력을 어떻게 처리하는지에 관해 설명한다
- 컴퓨터 시스템에 부착되는 입출력 장치들의 종류가 매우 다양하고 응용(프로그램?)들이 이러한 장치들의 모든 측면을 관리할 수 있도록 광범위한 기능을 제공해야 한다
- I/O 시스템 설계, 인터페이스, 그리고 내부 시스템 구조 및 기능을 포함한 시스템 I/O를 깊이 있게 논의한다
- 여러 면에서 입출력 장치는 컴퓨터 시스템의 주요 구성요소 중에서 가장 느리게 동작하는 구성요소이다
- 장치들이 성능의 병목 지점으로 작용하기 때문에 입출력 장치들에 관한 성능문제들도 검토한다

#### 6. 파일 시스템

- 13장부터 15장까지는 최신 컴퓨터 시스템에서 파일 시스템을 처리하는 방법에 대해 설명한다
- 파일 시스템은 데이터와 프로그램을 온라인으로 저장하고 접근하기 위한 기법을 제공한다
- 이 장들은 저장장치 관리를 위한 고전적인 내부 알고리즘들과 그 구조를 다룬다
- 또한 사용되는 알고리즘의 속성, 장점 및 단점에 대한 견고한 실질적인 이해를 제공한다

#### 7. 보안 및 보호

- 16장과 17장은 컴퓨터 시스템의 보안과 보호를 위해 필요한 기법들에 대해 논의한다
- 운영체제 내의 다양한 프로세스들은 다른 프로세스들의 활동으로 부터 보호되어야 한다
- 그런 보호를 제공하기 위해서 운영체제로부터 적절한 인가를 획득한 프로세스만이 파일, 메모리, CPU 및 다른 자원에 대해 연산을 하도록 보장해야 한다
- 보호는 프로그램, 프로세스, 또는 사용자들이 컴퓨터 시스템 자원에 대한 접근을 제어하기 위한 기법이다
  - 이 기법은 시행될 제어를 지정할 방법과 이들을 강제하려는 방법을 제공해야 한다
- 보안은 인가되지 않은 접근, 악의적 파괴 또는 변경, 그리고 비일관성의 우연한 도입으로부터 시스템에 저장된 정보(데이터 및 코드 모두)의 일관성과 시스템의 물리 자원들을 보호한다

#### 8. 고급 주제

- 18장과 19장에서는 가상 머신과 네트워크/분산 시스템에 대해 논의한다
- 18장에서는 가상 머신과 그것의 최신 운영체제와의 관계에 대해 개괄적으로 설명한다
  - 가상화를 가능하게 하는 하드웨어 및 소프트웨어 기술에 대한 일반적인 설명이 포함되어 있다
- 19장에서는 인터넷과 TCP/IP를 중심으로 컴퓨터 네트워크 및 본산 시스템에 대한 개요를 제공한다

#### 9. 사례 연구

- 20장과 21장은 두 개의 실제 운영체제인 Linux와 Windows 10에 대한 상세한 사례 연구를 제시한다

#### 10. 부록

- 부록 A는 더는 사용되지 않는 오래된 영향력 있는 운영체제에 관해 설명한다
- 부록 B에서 D는 Windows7, BSD 및 Mach라는 세 가지 이전 운영체제를 자세히 다룬다

### 프로그래밍 환경

- 이 책은 C언어와 Java언어로 작성된 여러 예제 프로그램을 제공한다
  - POSIX
  - Java
  - Windows 시스템

## 차례(Contents)

- 서문

### Part 1. 개관(Overview)

#### 1. 서론

- 1.1 운영체제가 할 일
- 1.2 컴퓨터 시스템의 구성
- 1.3 컴퓨터 시스템 구조
- 1.4 운영체제의 작동
- 1.5 자원 관리
- 1.6 보안과 보호
- 1.7 가상화
- 1.8 분산 시스템
- 1.9 커널 자료구조
- 1.10 계산 환경
- 1.11 무료 및 공개 소스 운영체제
- 1.12 요약, 연습문제, 추가 자료

#### 2. 운영체제 구조

- 2.1 운영체제 서비스
- 2.2 사용자와 운영체제 인터페이스
- 2.3 시스템 콜
- 2.4 시스템 서비스
- 2.5 링커와 로더
- 2.6 응용 프로그램이 운영체제마다 다른 이유
- 2.7 운영체제 설계 및 구현
- 2.8 운영체제 구조
- 2.9 운영체제 빌딩과 부팅
- 2.10 운영체제 디버깅
- 2.11 요약, 연습문제, 추가 자료

### Part 2. 프로세스 관리

#### 3. 프로세스

- 3.1 프로세스 개념
- 3.2 프로세스 스케쥴링
- 3.3 프로세스에 대한 연산
- 3.4 프로세스 간 통신
- 3.5 공유 메모리 시스템에서의 프로세스 간 통신
- 3.6 메세지 전달 시스템에서의 프로세스 간 통신
- 3.7 IPC 시스템의 사례
- 3.8 클라이언트 서버 환경에서 통신
- 3.9 요약, 연습문제, 추가 자료

#### 4. 스레드와 병행성

- 4.1 개요
- 4.2 다중 코어 프로그래밍
- 4.3 다중 스레드 모델
- 4.4 스레드 라이브러리
- 4.5 암묵적 스레딩
- 4.6 스레드와 관련된 문제들
- 4.7 운영체제 사례
- 4.8 요약, 연습문제, 추가 자료

#### 5. CPU 스케줄링

- 5.1 기본 개념
- 5.2 스케줄링 기준
- 5.3 스케줄링 알고리즘
- 5.4 스레드 스케줄링
- 5.5 다중 처리기 스케줄링
- 5.6 실시간 CPU 스케줄링
- 5.7 운영체제 사례들
- 5.8 알고리즘의 평가
- 5.9 요약, 연습문제, 추가 자료

### Part3. 프로세스 동기화

#### 6. 동기화 도구들

- 6.1 배경
- 6.2 임계구역 문제
- 6.3 Peterson의 해결안
- 6.4 동기화를 위한 하드웨어 지원
- 6.5 Mutex Locks
- 6.6 세마포
- 6.7 모니터
- 6.8 라이브니스
- 6.9 평가
- 6.10 요약, 연습문제, 추가 자료

#### 7. 동기화 예제

- 7.1 고전적인 동기화 문제들
- 7.2 커널 안에서의 동기화
- 7.3 POSIX 동기화
- 7.4 Java에서의 동기화
- 7.5 대체 방안들
- 7.6 요약, 연습문제, 추가 자료

#### 8. 교착 상태

- 8.1 시스템 모델
- 8.2 다중 스레드 응용에서의 교착 상태
- 8.3 교착 상태 특성
- 8.4 교착 상태 처리 방법
- 8.5 교착 상태 예방
- 8.6 교착 상태 회피
- 8.7 교착 상태 탐지
- 8.8 교착 상태로부터 회복
- 8.9 요약, 연습문제, 추가 자료

### Part4. 메모리 관리

#### 9. 메인 메모리

- 9.1 배경
- 9.2 연속 메모리 할당
- 9.3 페이징
- 9.4 페이지 테이블의 구조
- 9.5 스와핑
- 9.6 사례: Intel 32비트와 64비트 구조
- 9.7 사례: ARM 구조
- 9.8 요약, 연습문제, 추가 자료

#### 10. 가상 메모리

- 10.1 배경
- 10.2 요구 페이징
- 10.3 쓰기 시 복사
- 10.4 페이지 교체
- 10.5 프레임의 할당
- 10.6 스래싱
- 10.7 메모리 압축
- 10.8 커널 메모리의 할당
- 10.9 기타 고려 사항
- 10.10 운영체제의 예
- 10.11 요약, 연습문제, 추가 자료

### Part5. 저장장치 관리

#### 11. 대용량 저장장치 구조

- 11.1 대용량 저장장치 구조의 개관
- 11.2 디스크 스케줄링
- 11.3 NVM 스케줄링
- 11.4 오류 감지 및 수정
- 11.5 저장장치 관리
- 11.6 스왑 공간 관리
- 11.7 저장장치 연결
- 11.8 RAID 구조
- 11.9 요약, 연습문제, 추가 자료

#### 12. 입출력 시스템

- 12.1 개관
- 12.2 입출력 하드웨어
- 12.3 응용 입출력 인터페이스
- 12.4 커널 입출력 서브시스템
- 12.5 입출력 요구를 하드웨어 연산으로 변환
- 12.6 STREAMS
- 12.7 성능
- 12.8 요약, 연습문제, 추가 자료

### Part6. 파일 시스템

#### 13. 파일 시스템 인터페이스

- 13.1 파일 개념
- 13.2 접근 방법
- 13.3 디렉터리 구조
- 13.4 보호
- 13.5 메모리 사상 파일
- 13.6 요약, 연습문제, 추가 자료

#### 14. 파일 시스템 구현

- 14.1 파일 시스템 구조
- 14.2 파일 시스템 구현
- 14.3 디렉터리 구현
- 14.4 할당 방법
- 14.5 가용 공간의 관리
- 14.6 효율과 성능
- 14.7 복구
- 14.8 예: WAFL 파일 시스템
- 14.9 요약, 연습문제, 추가 자료

#### 15. 파일 시스템 내부구조

- 15.1 파일 시스템
- 15.2 파일 시스템 마운팅
- 15.3 파티션과 마운팅
- 15.4 파일 공유
- 15.5 가상 파일 시스템
- 15.6 원격 파일 시스템
- 15.7 일관성의 의미
- 15.8 NFS
- 15.9 요약, 연습문제, 추가 자료

### Part7. 보안과 보호

#### 16. 보안

- 16.1 보안 문제
- 16.2 프로그램 위협
- 16.3 시스템과 네트워크 위협
- 16.4 보안 도구로서 암호 기법
- 16.5 사용자 인증
- 16.6 보안 방어의 구현
- 16.7 예: Windows 10
- 16.8 요약, 추가 자료

#### 17. 보호

- 17.1 보호의 목표
- 17.2 보호의 원칙
- 17.3 보호 링
- 17.4 보호의 영역
- 17.5 접근 행렬
- 17.6 접근 행렬의 구현
- 17.7 접근 권한의 취소
- 17.8 역할 기반 액세스 제어
- 17.9 강제적 접근 제어
- 17.10 자격-기반 시스템
- 17.11 기타 보호 개선 방법
- 17.12 언어 기반의 보호
- 17.13 요약, 추가 자료

### Part8. 진보된 주제

#### 18. 가상 머신

- 18.1 개요
- 18.2 역사
- 18.3 장점 및 특징
- 18.4 빌딩 블록
- 18.5 VM 유형 및 구현
- 18.6 가상화와 운영체제 구성요소
- 18.7 사례
- 18.8 가상화 연구
- 18.9 요약, 추가 자료

#### 19. 네트워크 및 분산 시스템

- 19.1 분산 시스템의 장점
- 19.2 네트워크 구조
- 19.3 통신 구조
- 19.4 네트워크 및 분산 운영체제
- 19.5 분산 시스템의 설계 문제
- 19.6 분산 파일 시스템
- 19.7 DFS 명명 및 투명성
- 19.8 원격 파일 액세스
- 19.9 분산 파일 시스템에 대한 최종 생각
- 19.10 요약, 연습 문제, 추가 자료

### Part9. 사례 검토

#### 20. Linux 시스템

- 20.1 Linux 역사
- 20.2 설계 원칙
- 20.3 커널 모듈
- 20.4 프로세스 관리
- 20.5 스케줄링
- 20.6 메모리 관리
- 20.7 파일 시스템
- 20.8 입/출력
- 20.9 프로세스 간 통신
- 20.10 네트워크 구조
- 20.11 보안
- 20.12 요약, 연습문제, 추가 자료

#### 21. 윈도우

- 21.1 역사
- 21.2 설계 원칙
- 21.3 시스템 구성요소
- 21.4 터미널 서비스와 빠른 사용자 교체
- 21.5 파일 시스템
- 21.6 네트워킹
- 21.7 프로그래머 인터페이스
- 21.8 요약, 연습 문제, 추가 자료

### Part10. 부록

#### A. 영향력 있는 운영체제

- A.1 기능 전이
- A.2 초기 시스템
- A.3 Atlas
- A.4 XDS-940
- A.5 THE
- A.6 RC 4000
- A.7 CTSS
- A.8 MULTICS
- A.9 IBM OS/360
- A.10 TOPS-20
- A.11 CP/M과 MS/DOS
- A.12 Macintosh 운영체제와 Windows
- A.13 Mach
- A.14 자격-기반 시스템-Hydra 및 CAP
- A.15 기타 시스템들, 추가 자료

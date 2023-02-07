#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// 연습분제 3.1
int value = 5;
int main() {
  pid_t pid;
  pid = fork(); // 1. fork 시점 value : 5
  if (pid == 0) { // 4. 자식 프로세스가 실행
    // child process
    value += 15; // 자식 프로세스에 있는 value는 20이지만 부모 프로세스에 영향을 주지 않음 -> 따라서 부모 프로세스에 있는 value는 그대로 5
    return 0; // 5. 자식 프로세스 종료
  } else if (pid > 0) { // 2. 처음에 부모 프로세스가 실행
    // parent process
    wait(NULL); // 3. 자식 프로세스가 끝날 때까지 기다림
    printf("PARENT: value = %d\n", value); // LINE A
  }
}
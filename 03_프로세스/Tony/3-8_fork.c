#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid;
  // 새 프로세스를 생성(fork)
  pid = fork();
  if (pid < 0) {
    // 오류가 발생했음
    fprintf(stderr, "Fork Failed");
    return 1;
  } else if (pid == 0) {
    // 자식 프로세스
    execlp("/bin/ls", "ls", NULL);
    printf("실행되는가?"); // 실행되지 않음 - ls로 갈아끼웠기 때문
  } else {
    // 부모 프로세스
    // 자식 프로세스가 끝날 때까지 기다림
    wait(NULL);
    printf("Child Complete");
  }
  return 0;
}
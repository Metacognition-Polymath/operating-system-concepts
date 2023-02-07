#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/**
 * 연습문제 3.2
 * How many processes are created?
*/
int main() {
  fork();
  fork();
  fork();
  printf("Hello\n");
  return 0;
}
#include <stdio.h>
#include <unistd.h>

/**
 * How many processes are created?
*/
int main() {
  int i;
  pid_t pid;
  for (i = 0; i < 2; i++) {
    pid = fork();
  }
  printf("Hello!!%d\n", pid);
  return 0;
}
// 2^4 = 16
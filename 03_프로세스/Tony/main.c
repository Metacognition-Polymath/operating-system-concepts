#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork(); // pid = 0, 자식 프로세스
    printf("Hello, Process! %d\n", pid);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  // the size (in bytes) of shared memory object
  const int SIZE = 4096;
  // name of the shared memory object
  const char *name = "OS";
  // strings written to shared memory
  const char *message_0 = "Hello";
  const char *message_1 = "World!";

  // shared memory file descriptor
  int fd;
  // pointer to shared memory object
  char *ptr;

  // create the shared memory object
  fd = shm_open(name, O_CREAT | O_RDWR, 0666);
  // configure the size of the shared memory object
  ftruncate(fd, SIZE);
  // memory map the shared memory object
  ptr = (char *)mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

  // write to the shared memory object
  sprintf(ptr, "%s", message_0);
  ptr += strlen(message_0);
  sprintf(ptr, "%s", message_1);
  ptr += strlen(message_1);

  return 0;
}
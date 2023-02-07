#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>

int main() {
  // the size (in bytes) of shared memory object
  const int SIZE = 4096;
  // name of the shared memory object
  const char *name = "OS";
  // shared memory file descriptor
  int fd;
  // pointer to shared memory object
  char *ptr;

  // open the shared memory object
  fd = shm_open(name, O_RDONLY, 0666);
  // memory map the shared memory object
  ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
  // read from the shared memory object
  printf("%s", ptr);
  // remove the shared memory object
  shm_unlink(name);

  return 0;
}
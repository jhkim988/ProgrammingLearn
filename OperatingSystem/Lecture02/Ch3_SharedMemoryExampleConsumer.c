#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096;
    const char* name = "OS";

    int shm_fd;
    char* ptr;

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ptr = (char*) mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s", (char*) ptr);

    shm_unlink(name);

    return 0;

    // gcc Ch3_SharedMemoryExampleConsumer.c -lrt
    // -lrt: rt 라이브러리를 이용
}
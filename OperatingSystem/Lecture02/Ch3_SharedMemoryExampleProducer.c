#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // oflag: O_CREATE, O_RDWR 등 파일 open 옵션
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096; // name of shared memory
    const char* name = "OS"; // name of shared memory
    const char* message_0 = "Hello, ";
    const char* message_1 = "Shared Memory!\n";

    int shm_fd;
    char* ptr;

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); // shared memory open, shm_open(name, oflag, mode_t);
    // oflag: file open option, <fcntl.h>
    // mode_t: UNIX 접근 권한, 0666 = 파일 접근, 0777 = 디렉토리 접근

    ftruncate(shm_fd, SIZE); // change file size using file descripter(POSIX O/S)
    ptr = (char*) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); // pointer of shared memory
    // mmap(start, length/size, memory protect mode, flag, file decripter, offset);

    sprintf(ptr, "%s", message_0); // write message
    ptr += strlen(message_0); // move pointer
    sprintf(ptr, "%s", message_1); // write message
    ptr += strlen(message_1); // move pointer

    return 0;

    // gcc Ch3_SharedMemoryExampleProducer.c -lrt
    // -lrt: rt 라이브러리를 이용
}
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd = open("sample.txt", O_RDWR);
    char *data = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%s\n", data);
    strcpy(data, "Memory Mapped File");
    munmap(data,100);
    close(fd);
    return 0;
}


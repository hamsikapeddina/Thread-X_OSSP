#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd;
    char message[100];
    fd = open("client_fifo", O_WRONLY);
    strcpy(message, "Hello Server");

    write(fd, message, strlen(message) + 1);
    close(fd);

    fd = open("server_fifo", O_RDONLY);
    read(fd, message, sizeof(message));
    printf("Server: %s\n", message);

    close(fd);
    return 0;

}

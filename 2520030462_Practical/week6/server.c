#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char buffer[100];

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    printf("Server waiting for client...\n");

    int fd1 = open(FIFO1, O_RDONLY);

    read(fd1, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    close(fd1);

    int fd2 = open(FIFO2, O_WRONLY);

    char response[] = "Message processed by server";
    write(fd2, response, strlen(response) + 1);

    close(fd2);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}

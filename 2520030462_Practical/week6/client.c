#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char message[100];
    char buffer[100];

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    int fd1 = open(FIFO1, O_WRONLY);

    write(fd1, message, strlen(message) + 1);

    close(fd1);

    int fd2 = open(FIFO2, O_RDONLY);

    read(fd2, buffer, sizeof(buffer));

    printf("Server: %s\n", buffer);

    close(fd2);

    return 0;
}


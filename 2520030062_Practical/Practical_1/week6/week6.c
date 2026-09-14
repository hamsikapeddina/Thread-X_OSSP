#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char message[100];

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    printf("Server started. Waiting for client...\n");

    int read_fd = open(FIFO1, O_RDONLY);
    int write_fd = open(FIFO2, O_WRONLY);

    read(read_fd, message, sizeof(message));

    printf("Client sent: %s\n", message);

    char response[] = "Message received by server successfully.";

    write(write_fd, response, strlen(response) + 1);

    printf("Response sent to client.\n");

    close(read_fd);
    close(write_fd);

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}

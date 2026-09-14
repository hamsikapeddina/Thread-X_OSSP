#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char message[] = "Hello Server!";
    char response[100];

    int write_fd = open(FIFO1, O_WRONLY);
    int read_fd = open(FIFO2, O_RDONLY);

    write(write_fd, message, sizeof(message));

    printf("Message sent to server: %s\n", message);

    read(read_fd, response, sizeof(response));

    printf("Server response: %s\n", response);

    close(write_fd);
    close(read_fd);

    return 0;
}

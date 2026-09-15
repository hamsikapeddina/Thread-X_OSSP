#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    int fd;
    char message[100];
mkfifo("client_fifo", 0666);
mkfifo("server_fifo", 0666);
printf("Server waiting...\n");
fd = open("client_fifo", O_RDONLY);
read(fd, message, sizeof(message));
printf("Client: %s\n", message);
close(fd);
fd = open("server_fifo", O_WRONLY);
strcpy(message, "Message processed by server");
write(fd, message, strlen(message) + 1);
close(fd);
return 0;
}

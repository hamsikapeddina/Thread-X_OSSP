#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    dup2(fd, STDOUT_FILENO);
    printf("This output is redirected to output.txt\n");
    close(fd);
    return 0;
}

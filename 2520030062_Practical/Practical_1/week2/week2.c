#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd1, fd2;
    char buffer[1024];
    ssize_t bytes;

    fd1 = open("source.txt", O_RDONLY);

    if (fd1 == -1)
    {
        printf("Error opening source file\n");
        return 1;
    }

    fd2 = open("destination.txt",
               O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1)
    {
        printf("Error creating destination file\n");
        close(fd1);
        return 1;
    }

    while ((bytes = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, bytes);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully.\n");

    return 0;
}

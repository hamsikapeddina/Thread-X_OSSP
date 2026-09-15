#include <stdio.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[1024];
    int bytesRead, bytesWritten;

    source = open("sample.txt", O_RDONLY);

    if (source == -1)
    {
        printf("Error opening source file\n");
        return 1;
    }

    destination = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination == -1)
    {
        printf("Error opening destination file\n");
        close(source);
        return 1;
    }

    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0)
    {
        bytesWritten = write(destination, buffer, bytesRead);

        if (bytesWritten == -1)
        {
            printf("Error writing to destination file\n");
            close(source);
            close(destination);
            return 1;
        }
    }

    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}

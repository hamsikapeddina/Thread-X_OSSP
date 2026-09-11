#include <stdio.h>
#include <unistd.h>

int main()
{
    int p[2];
    char msg[] = "Hello";
    char buffer[20];

    pipe(p);

    if(fork() == 0)
    {
        close(p[1]);

        read(p[0], buffer, sizeof(buffer));

        printf("Child received: %s\n", buffer);
    }
    else
    {
        close(p[0]);

        write(p[1], msg, sizeof(msg));

        printf("Parent sent: %s\n", msg);
    }

    return 0;
}

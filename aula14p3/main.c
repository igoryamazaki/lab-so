#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    mkfifo("/tmp/pipe1", 0666);

    int fd = open("/tmp/pipe1", O_WRONLY);

    if (fd == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    char msg[100] = "Hello, World!";
    write(fd, msg, strlen(msg) + 1);
    close(fd);

    return 0;
}

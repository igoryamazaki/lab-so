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

    int fd = open("/tmp/pipe1", O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    char msg[100] = "Hello, World!";
    read(fd, msg, strlen(msg) + 1);
    printf("Mensagem lida: %s\n", msg);
    close(fd);

    return 0;
}
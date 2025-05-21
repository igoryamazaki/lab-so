#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    umask(0);
    char s = 'B'; // agora s é só um char
    int fd;

    fd = open("teste.txt", O_WRONLY);

    write(fd, &s, 1);
    close(fd);

    return 0;
}

// aula de revisão
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    mkfifo("/tmp/pipe", 0666);
    int fd = open("/tmp/pipe", O_WRONLY);
    if (fd == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    int k;
    for (int i = 0; i < 10; i++)
    {
        usleep(250000);
        write(fd, &k, sizeof(k));
        printf("[P1] Enviando: %d\n", k);
        k++;
    }
}
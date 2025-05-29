#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    mkfifo("/tmp/fifoVai", 0666);
    mkfifo("/tmp/fifoVem", 0666);

    int fd1 = open("/tmp/fifoVai", O_RDONLY);

    if (fd1 == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    int n, out;
    read(fd1, &n, sizeof(n));
    printf("[Programa 2] Valor recebido: %d\n", n);
    out = n * 2;

    close(fd1);

    int fd2 = open("/tmp/fifoVem", O_WRONLY);

    if (fd2 == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    write(fd2, &out, sizeof(out));

    printf("[Programa 2] Valor enviado: %d\n", out);
    close(fd2);

    return 0;
}
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

    int fd1 = open("/tmp/fifoVai", O_WRONLY);

    if (fd1 == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    int n;
    char str[25];
    printf("[Programa 1] Digite um valor: ");
    fgets(str, sizeof(str), stdin);
    n = atoi(str);

    printf("[Programa 1] Valor enviado: %d\n", n);
    write(fd1, &n, sizeof(n));
    close(fd1);

    int fd2 = open("/tmp/fifoVem", O_RDONLY);

    if (fd2 == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    read(fd2, &n, sizeof(n));

    printf("[Programa 1] Valor recebido: %d\n", n);
    close(fd2);

    return 0;
}

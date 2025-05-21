#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    umask(0);
    int x;
    int fd;
    fd = open("teste.txt", O_RDONLY, 0777);

    if (-1 == fd)
        return -1;

    read(fd, &x, 4);                              // lê do arq.
    printf("\n Imprimindo o byte em int: %d", x); // imprime na tela

    close(fd); // fechar arq

    return 0;
}
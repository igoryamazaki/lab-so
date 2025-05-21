#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    umask(0);
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // s é um ponteiro
    int n = 0;
    int fd;
    fd = open("teste.txt", O_RDONLY, 0777);

    if (-1 == fd)
        return -1;

    while (1)
    {
        read(fd, &s[n], 1); // lê do arq.
        /*
        fd - file descriptor
        &s[n] - endereço do elemento n
        1 - número de bytes a serem lidos
        */
        putchar(s[n]); // imprime na tela
        n++;
        if (n == 5)
            break;
    }

    close(fd); // fechar arq

    return 0;
}
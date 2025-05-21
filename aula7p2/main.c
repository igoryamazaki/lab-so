#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    umask(0);
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // s é um ponteiro
    int n, fd;
    fd = open("teste.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    /*
        O_WRONLY - open for writing only
        O_CREAT - create file if it does not exist
        O_TRUNC - truncate file to zero length if it exists

        S_IRUSR - user has read permission
        S_IWUSR - user has write permission
        ou 0777 - rwxrwxrwx (user, group, others) abilitando todas as permissões.
    */
    if (-1 == fd)
        return -1;
    write(fd, &s[0], 15);
    /*
    escreve no arq.
    sizeof nao funcionou (?).
    &s[0] endereço do primeiro elemento
    */
    close(fd); // fechar arq

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char maiscula(char c)
{
    return c - 'a' + 'A';
}

int main()
{
    int fd1[2], fd2[2];
    char in[100] = "abcdef";
    char out[100];

    pipe(fd1);
    pipe(fd2);
    int pid = fork();

    if (pid == 0)
    {
        close(fd1[1]);                  // fecha escrita
        read(fd1[0], out, sizeof(out)); //"ouve"

        printf("(2) filho[%d] out: %s\n", pid, out);
        char maisculo_out[100];
        for (int i = 0; i < strlen(out); i++)
            maisculo_out[i] = maiscula(out[i]);

        printf("(3) filho[%d] in: %s\n", pid, maisculo_out);

        close(fd2[0]);                                     // fecha leitura
        write(fd2[1], maisculo_out, strlen(maisculo_out)); //"fala"
    }
    else
    {
        close(fd1[0]);                 // fecha leitura
        write(fd1[1], in, strlen(in)); //"fala"

        printf("(1) pai[%d] in: %s\n", pid, in);

        char maisculo_in[100];
        close(fd2[1]);                                  // fecha escrita
        read(fd2[0], maisculo_in, sizeof(maisculo_in)); //"ouve"

        printf("(4) pai[%d] out: %s\n", pid, maisculo_in);
    }
}
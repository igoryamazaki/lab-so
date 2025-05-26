#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    char in[100] = "Hello";
    char out[100];

    pipe(fd);
    int pid = fork();

    if (pid == 0)
    {
        close(fd[1]); // fecha escrita
        read(fd[0], out, sizeof(out));

        printf("filho[%p %d] out: %s\n", main, pid, out);
    }
    else
    {
        close(fd[0]); // fecha leitura
        write(fd[1], in, strlen(in));

        printf("pai[%p %d] in: %s\n", main, pid, in);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>

int G = 0;

int main(int argc, char *argv[])
{
    int qntd_filhos = 5;
    G = 111;

    printf("pai: %p %p %d %d\n", main, &G, G, getpid());

    for (int i = 0; i < qntd_filhos; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            G = 123;
            printf("filho: %p %p %d %d\n", main, &G, G, getpid());
            exit(0); // termina o processo filho
        }
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int G = 0;

int main()
{
    int pid = fork();

    if (fork() == 0)
    {
        G = 123;
        printf("filho: %p %p %d %d\n", main, &G, G, pid);
    }
    else if (fork() != 0 && pid != 0)
    {
        G = 777;
        printf("pai: %p %p %d %d\n", main, &G, G, pid);
    }
}
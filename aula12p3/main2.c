#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("%d", getpid());
}
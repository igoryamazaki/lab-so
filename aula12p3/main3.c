#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 100000000 * 2
int buffer[N];
int main()
{
    int i, s;
    for (i = 0; i < N / 2; i++)
        s += buffer[i] + 1;

    printf("%d\n", getpid());
    printf("soma 1 = %d\n", s);

    fork();
    printf("Com fork ");

    for (i = N / 2; i < N; i++)
        s += buffer[i] + 1;

    printf("%d\n", getpid());
    printf("soma 2 = %d\n", s);
}
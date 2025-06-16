#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// teste com 100000 para ver a race condition

int GNvezes;
int Global = 0;

void *f_add(void *p)
{
    for (int i = 0; i < GNvezes; i++)
        Global++;
}

void *f_dim(void *p)
{
    for (int i = 0; i < GNvezes; i++)
        Global--;
}

void main(int argc, char *argv[])
{

    GNvezes = atoi(argv[1]);

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, f_add, NULL);
    pthread_create(&tid2, NULL, f_dim, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Global = %d\n", Global);
}
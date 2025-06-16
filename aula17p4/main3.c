#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// solução de Peterson para a race condition
// é possível perceber que não resolve o problema de forma eficiente
// mas aminiza

// testar com 100000
int Gturn = 0;
int Gflag[2] = {0, 0};

int GNvezes;
int Global = 0;

void *f_add(void *p)
{
    for (int i = 0; i < GNvezes; i++)
    {
        Gflag[0] = 1;
        Gturn = 1;
        while (Gflag[1] && Gturn == 1)
        {
            ;
        }
        Global++;
        Gflag[0] = 0;
    }
}

void *f_dim(void *p)
{
    for (int i = 0; i < GNvezes; i++)
    {
        Gflag[1] = 1;
        Gturn = 0;
        while (Gflag[0] && Gturn == 0)
        {
            ;
        }
        Global--;
        Gflag[1] = 0;
    }
}
void main(int argc, char *argv[])
{

    GNvezes = atoi(argv[1]);

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, f_add, NULL);
    pthread_create(&tid2, NULL, f_dim, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Com Solução de Peterson:\nGlobal = %d\n", Global);
}
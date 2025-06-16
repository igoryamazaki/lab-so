#include <stdio.h>
#include <pthread.h>

void *f(void *p)
{
    for (int i = 0; i < 200; i++)
        printf("%d", i);
}

int main()
{
    pthread_t tid1, tid2;
    puts("\noi");
    pthread_create(&tid1, NULL, f, NULL);
    pthread_create(&tid2, NULL, f, NULL);

    puts("\noi2");
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    puts("\nfim");
}
#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec start, end;
    double elapsed_time;

    // Capturando o tempo antes do loop
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    volatile long i;
    for (i = 0; i < 100000000; i++)
        ;

    // Capturando o tempo após o loop
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    // Cálculo do tempo decorrido em segundos
    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Tempo de execucao: %.9f segundos\n", elapsed_time);
    return 0;
}
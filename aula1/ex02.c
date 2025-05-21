#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void esperar(double segundos)
{
    struct timespec inicio, atual;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    do
    {
        clock_gettime(CLOCK_MONOTONIC, &atual);
    } while ((atual.tv_sec - inicio.tv_sec) +
                 (atual.tv_nsec - inicio.tv_nsec) / 1e9 <
             segundos);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <tempo_em_segundos>\n", argv[0]);
        return 1;
    }

    double tempo = atof(argv[1]);
    if (tempo <= 0)
    {
        fprintf(stderr, "Erro: O tempo deve ser um número positivo.\n");
        return 1;
    }

    printf("Aguardando %.2f segundos...\n", tempo);
    esperar(tempo);

    printf("Finalizando o programa.\n");
    return 0;
}

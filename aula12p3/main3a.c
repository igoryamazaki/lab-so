#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>

#define N (100000000 * 2)
int buffer[N];

// Função para calcular tempo em milissegundos
double tempo_em_ms()
{
    struct timeval tempo;
    gettimeofday(&tempo, NULL);
    return tempo.tv_sec * 1000.0 + tempo.tv_usec / 1000.0;
}

int main()
{
    long long soma = 0;
    int i;

    // Preenche o buffer com 1s
    for (i = 0; i < N; i++)
        buffer[i] = 1;

    // ==========================
    // PARTE 1: SEM FORK (sequencial)
    // ==========================
    double inicio_sem_fork = tempo_em_ms();

    soma = 0;
    for (i = 0; i < N; i++)
        soma += buffer[i];

    double fim_sem_fork = tempo_em_ms();
    printf("=== SEM FORK ===\n");
    printf("Soma total: %lld\n", soma);
    printf("Tempo: %.2f ms\n\n", fim_sem_fork - inicio_sem_fork);

    // ==========================
    // PARTE 2: COM FORK (paralelo)
    // ==========================
    double inicio_com_fork = tempo_em_ms();

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork falhou");
        exit(1);
    }
    else if (pid == 0)
    {
        // Processo filho: soma a segunda metade
        long long soma_filho = 0;
        for (i = N / 2; i < N; i++)
            soma_filho += buffer[i];
        printf("[Filho %d] Soma parcial = %lld\n", getpid(), soma_filho);
        exit(0);
    }
    else
    {
        // Processo pai: soma a primeira metade
        long long soma_pai = 0;
        for (i = 0; i < N / 2; i++)
            soma_pai += buffer[i];
        printf("[Pai %d] Soma parcial = %lld\n", getpid(), soma_pai);

        wait(NULL); // espera o filho terminar

        double fim_com_fork = tempo_em_ms();
        printf("\n=== COM FORK ===\n");
        printf("Tempo: %.2f ms\n", fim_com_fork - inicio_com_fork);
    }

    return 0;
}

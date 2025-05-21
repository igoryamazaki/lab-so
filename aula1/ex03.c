#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
Para executar esse código, usa-se o comando no terminal: time ./ex03 3.5
O time é uma ferramenta do Linux usada para medir quanto tempo um programa leva para ser executado.

o que ocorre?
1- O shell (bash, zsh, etc.) encontra e executa o programa ./ex02 com o argumento 3.5.
2- O programa ./ex02 roda e aguarda 3.5 segundos devido ao uso de nanosleep().
3- O comando time mede o tempo de execução e exibe três métricas:
real	Tempo total desde o início até o fim da execução do programa, incluindo tempo de espera.
user	Tempo que a CPU gastou executando o código do usuário (instruções da aplicação).
sys	Tempo que a CPU gastou executando chamadas de sistema (funções do kernel, como nanosleep()).
*/
void esperar(double segundos)
{
    struct timespec tempo;
    tempo.tv_sec = (time_t)segundos;                         // Parte inteira em segundos
    tempo.tv_nsec = (long)((segundos - tempo.tv_sec) * 1e9); // Parte fracionária em nanosegundos
    nanosleep(&tempo, NULL);                                 // coloca o processo em modo de espera sem ocupar CPU
    /*
    NULL significa que não há necessidade de armazenar
    o tempo restante caso o sono seja interrompido
    */
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <tempo_em_segundos>\n", argv[0]);
        return 1;
    }

    double tempo = atof(argv[1]); // Converte a entrada (argv[1]) para um número decimal (double)
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

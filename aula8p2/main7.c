#include <stdio.h>
#include <unistd.h>
#include <time.h>

char buffer[1024 * 1024]; // buffer de 1MB
struct timespec start, end;
double elapsed_time;

void copiar(int N)
{
    FILE *rb = fopen("arquivo_grande.txt", "rb");
    FILE *wb = fopen("copiar.dat", "wb");

    if (!rb || !wb)
    {
        perror("Erro ao abrir arquivos");
        if (rb)
            fclose(rb);
        if (wb)
            fclose(wb);
        return;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    size_t bytes_lidos;
    while ((bytes_lidos = fread(buffer, 1, N, rb)) > 0)
    {
        fwrite(buffer, 1, bytes_lidos, wb);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_time = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;

    fclose(rb);
    fclose(wb);
}

int main()
{
    int N = 1;

    while (N <= 1024 * 1024)
    {
        copiar(N);
        printf("Tamanho do bloco: %d bytes | Tempo de execucao: %.9f segundos\n", N, elapsed_time);
        N *= 2;
    }

    return 0;
}

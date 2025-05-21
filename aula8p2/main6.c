#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// neste código, o buffer é escrito no arquivo antes de o processo ser morto
// logo, é possível ver que o buffer tem 4096 Bytes, pois o 'B' nao foi escrito
int main()
{
    FILE *fp = fopen("teste.txt", "w");
    for (int i = 0; i < 4096; i++)
    {
        fwrite("a", 1, 1, fp);
    }
    fwrite("B", 1, 1, fp);
    kill(getpid(), SIGKILL);
}
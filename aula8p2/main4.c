#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    FILE *fp = fopen("teste.txt", "w");
    fwrite("Abc\n", 1, 12, fp);
    fflush(fp);
    // fflush -> escreve o buffer no arquivo
    kill(getpid(), SIGKILL);
    // getpid() -> retorna o pid do processo atual
    // kill -> envia sinal para o processo
    // SIGKILL -> sinal de kill
    // nao chega no fclose
    fclose(fp);
}
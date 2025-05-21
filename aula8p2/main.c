#include <stdio.h>

int main()
{
    FILE *fp = fopen("teste.txt", "w");
    // fp->_fileno = 1; // 1 -> stdout
    // isso faz com que o arquivo seja escrito na tela(todos perifericos sao tratados como arquivos)
    fwrite("Abc\n", 1, 12, fp); // fwrite -> write to file
    // 1 -> stdout
    // 12 -> size
    // fwrite -> write to file
    fclose(fp);
}
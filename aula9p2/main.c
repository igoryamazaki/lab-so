#include <stdio.h>

int main()
{
    FILE *fp = fopen("/mnt/c/temp", "rb"); // Certifique-se de que o caminho está correto
    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    unsigned char buffer[20];
    size_t lidos = fread(buffer, 1, 20, fp);
    for (size_t i = 0; i < lidos; i++)
    {
        printf("Byte %02zu: char = '%c' | int = %3d\n", i, buffer[i], buffer[i]);
    }

    fclose(fp);
    return 0;
}

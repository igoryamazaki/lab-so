#include <stdio.h>

int main()
{
    FILE *fp = fopen("/Aula15ExemploGerarDiagrama", "wb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fwrite("abc", sizeof(char), 3, fp);
    fclose(fp);
}
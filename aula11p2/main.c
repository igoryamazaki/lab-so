#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo;
    char linha[1000];
    char palavra[50];
    int k = 0;

    arquivo = fopen("FILE", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo))
    {
        int tamanho = strlen(linha);
        for (int i = 0; i < tamanho; i++)
        {
            palavra[k] = linha[i];
            k++;
            if (linha[i] == ':' || linha[i] == '\n')
            {
                palavra[k - 1] = '\0';
                printf("%s\n", palavra);
                for (int j = 0; j < k - 1; j++)
                {
                    palavra[j] = '\0';
                }
                k = 0;
            }
        }
    }

    fclose(arquivo);
    return 0;
}

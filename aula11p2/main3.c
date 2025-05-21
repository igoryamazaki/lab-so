#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo = fopen("/etc/group", "rt");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char linha[512];
    char palavra[100];
    int k = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) //
    {
        int tamanho = strlen(linha); //
        for (int i = 0; i < tamanho + 1; i++)
        {
            palavra[k] = linha[i];
            k++;
            if (i == tamanho || linha[i] == ':')
            {
                palavra[k - 1] = '\0';
                printf("%s\n", palavra);

                for (int j = 0; j < k; j++)
                {
                    palavra[j] = '\0';
                }
                k = 0;
                if (linha[i] == '\0') //
                    break;
            }
        }
    }

    fclose(arquivo);
}

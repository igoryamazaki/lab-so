#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
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

    printf("Pesquisa pelo usuário: %s\n\n", argv[1]);

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int tamanho = strlen(linha);
        for (int i = 0; i < tamanho + 1; i++)
        {
            palavra[k] = linha[i];
            k++;
            if (i == tamanho)
            {
                palavra[k - 1] = '\0';

                if (!strstr(palavra, argv[1]) == 0)
                {
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (palavra[j] == ':')
                        {
                            palavra[j] = '\0';
                            printf("Usuário: %s | Grupo: %s\n", argv[1], palavra);
                            break;
                        }
                    }
                }

                for (int j = 0; j < k; j++)
                {
                    palavra[j] = '\0';
                }
                k = 0;
                if (linha[i] == '\0')
                    break;
            }
        }
    }

    fclose(arquivo);
}

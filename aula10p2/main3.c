#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <nome_do_processo>\n", argv[0]);
        return 1;
    }

    printf("Pesquisa do processo: %s\n", argv[1]);

    DIR *p = opendir("/proc");
    if (p == NULL)
    {
        perror("Erro ao abrir o diretório");
        return 1;
    }

    struct dirent *p2;
    char caminho_completo[1024];
    char caminho_status[1024];

    while ((p2 = readdir(p)) != NULL)
    {
        if (isdigit(p2->d_name[0]))
        {
            snprintf(caminho_completo, sizeof(caminho_completo), "/proc/%s/comm", p2->d_name);

            FILE *file = fopen(caminho_completo, "rt");
            if (file != NULL)
            {
                char comm[256];
                if (fgets(comm, sizeof(comm), file) != NULL)
                {
                    comm[strcspn(comm, "\n")] = 0; // Remove o \n

                    if (strcmp(comm, argv[1]) == 0)
                    {
                        printf("Processo: %s. PID: %s\n", argv[1], p2->d_name);

                        snprintf(caminho_status, sizeof(caminho_status), "/proc/%s/status", p2->d_name);
                        FILE *file2 = fopen(caminho_status, "rt");
                        if (file2 != NULL)
                        {
                            char linha[256];
                            while (fgets(linha, sizeof(linha), file2))
                            {
                                if (strncmp(linha, "State:", 6) == 0)
                                {
                                    linha[strcspn(linha, "\n")] = 0; // remove \n
                                    printf("%s\n", linha);
                                    break;
                                }
                            }
                            fclose(file2);
                        }
                    }
                }
                fclose(file);
            }
        }
    }

    closedir(p);
    return 0;
}

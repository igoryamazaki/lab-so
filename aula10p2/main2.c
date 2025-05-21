#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    printf("Pesquisa do processo: %s\n", argv[1]);

    DIR *p = opendir("/proc");
    if (p == NULL)
    {
        perror("Erro ao abrir o diretório");
        return 1;
    }

    struct dirent *p2;
    char caminho_completo[1024];

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
                    comm[strlen(comm) - 1] = 0;

                    if (strcmp(comm, argv[1]) == 0)
                        printf("Processo: %s. PID: %s. Caminho: %s\n", argv[1], p2->d_name, caminho_completo);
                }
                fclose(file);
            }
        }
    }
    closedir(p);
    return 0;
}
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

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
                    printf("caminho: %s", caminho_completo);
                    printf(": %s\n", comm);
                }
                fclose(file);
            }
        }
    }
    closedir(p);
    return 0;
}
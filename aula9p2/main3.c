#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s\n", argv[1]);
        return 1;
    }

    DIR *p = opendir(argv[1]);

    struct dirent *p2;
    struct stat reg;
    char full_path[1024];

    while ((p2 = readdir(p)) != NULL)
    {
        stat(full_path, &reg);

        snprintf(full_path, sizeof(full_path), "%s/%s", argv[1], p2->d_name);
        if (stat(full_path, &reg) == -1)
        {
            perror("Erro ao obter informações do arquivo");
            continue;
        }
        printf("File: %s\n", p2->d_name);
        printf("Size: %ld bytes\n", reg.st_size);

        printf("Permissions: ");
        printf((reg.st_mode & S_IRUSR) ? "r" : "-");
        printf((reg.st_mode & S_IWUSR) ? "w" : "-");
        printf((reg.st_mode & S_IXUSR) ? "x" : "-");
        printf((reg.st_mode & S_IRGRP) ? "r" : "-");
        printf((reg.st_mode & S_IWGRP) ? "w" : "-");
        printf((reg.st_mode & S_IXGRP) ? "x" : "-");
        printf((reg.st_mode & S_IROTH) ? "r" : "-");
        printf((reg.st_mode & S_IWOTH) ? "w" : "-");
        printf((reg.st_mode & S_IXOTH) ? "x" : "-");
        printf("\n----------------------\n");
    }
    closedir(p);
    return 0;
}

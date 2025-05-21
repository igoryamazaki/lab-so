#include <stdio.h>

int main()
{
    FILE *file = fopen("ex01.txt", "r");
    char buffer[20];
    int i = 0;
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // lendo todo o arquivo
    /*while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("Read: %s", buffer);
    }*/

    // lendo apenas as duas primeiras linhas
    while (i != 2)
    {
        fgets(buffer, sizeof(buffer), file);
        printf("Read: %s", buffer);
        i++;
    }

    if (feof(file))
    {
        printf("End of file reached.\n");
    }
    else if (ferror(file))
    {
        printf("An error occurred.\n");
    }

    fclose(file);
    return 0;
}
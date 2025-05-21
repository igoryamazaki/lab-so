#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Uso: ./main biblioteca.so num1 num2\n");
        return 1;
    }

    char *lib = argv[1];   // ex: Soma.so ou Sub.so
    int a = atoi(argv[2]); // num1
    int b = atoi(argv[3]); // num2

    void *pb = dlopen(lib, RTLD_NOW); // abrir biblioteca
    if (!pb)
    {
        printf("Erro ao abrir biblioteca: %s\n", dlerror());
        return 1;
    }

    int (*pf)(int, int); // ponteiro para função

    if (strcmp(lib, "./Soma.so") == 0)
        pf = dlsym(pb, "Soma");
    else if (strcmp(lib, "./Sub.so") == 0)
        pf = dlsym(pb, "Sub");
    else
    {
        printf("Erro: biblioteca desconhecida\n");
        dlclose(pb);
        return 1;
    }

    if (!pf)
    {
        printf("Erro ao carregar função: %s\n", dlerror());
        dlclose(pb);
        return 1;
    }

    int r = pf(a, b);
    printf("Resultado: %d\n", r);

    dlclose(pb);
    return 0;
}

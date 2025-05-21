#include <stdio.h>
#include <dlfcn.h>

int main()
{
    int x = 2;
    void *pb = dlopen("./Bib.so", RTLD_NOW); // abrir biblioteca
    if (pb == NULL)
    {
        printf("Error: %s\n", dlerror());
        return 1;
    }
    int (*pf)(int) = dlsym(pb, "fun"); // buscar funcao na biblioteca
    if (pf == NULL)
    {
        printf("Error: %s\n", dlerror());
        dlclose(pb);
        return 1;
    }
    int R = (*pf)(x); // chamar funcao
}

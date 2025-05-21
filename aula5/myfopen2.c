#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

FILE *(*fp)(const char *, const char *); // Ponteiro para função fopen
FILE *fopen(const char *p1, const char *p2)
{
    fp = dlsym(RTLD_NEXT, "fopen"); // Carrega a função original fopen
    puts("ueba");
    return (*fp)(p1, p2); // Chama a função original fopen
}
#include <stdio.h>

// Implementação personalizada de fopen
FILE *fopen(const char *s1, const char *s2) // filename, mode
{
    puts("oi");
    return 0; // Em vez de 0, que não é um ponteiro FILE* válido
}

#include <stdio.h>
extern "C"
{
    int soma(int, int);
}
int main()
{
    return printf("%d\n", soma(1, 1));
}
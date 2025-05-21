#include <stdio.h>

int main()
{
    FILE *fp = fopen("teste.txt", "w");
    fwrite("Abc\n", 1, 12, fp);
    fp->_IO_write_base[0] = 'X';

    fclose(fp);
}
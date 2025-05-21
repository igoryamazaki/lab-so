#include <stdio.h>

int main()
{
    FILE *fp = fopen("teste.txt", "w");
    fp->_IO_write_base[0] = 'X';
    fwrite("Abc\n", 1, 12, fp);

    fclose(fp);
}
// aula de revisão
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    sleep(3);
    int fd = open("/tmp/pipe", O_RDONLY | O_NONBLOCK);
    if (fd == -1)
    {
        perror("Error opening pipe");
        return 1;
    }

    int n, k;
    while (1)
    {
        n = read(fd, &k, sizeof(k));
        printf("[P2]: ");
        if (n == -1)
        {
            usleep(300000);
            printf("-\n");
        }
        else if (n == 0)
        {
            printf("Pipe fechado, fim...\n");
            exit(0);
        }
        else if (n > 0)
        {
            printf("%d\n", k);
        }
    }
}
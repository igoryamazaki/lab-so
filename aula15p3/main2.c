#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg
{
    long key;
    char buf[10];
};

int main()
{
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    struct msg reg;
    int pid = fork();

    if (pid == 0)
    { // filho
        reg.key = 1;
        msgrcv(id, &reg, sizeof(reg.buf), 1, 0);
        printf("Mensagem recebida: %s\n", reg.buf);
    }
    else
    { // pai
        reg.key = 1;
        strcpy(reg.buf, "ABC");
        msgsnd(id, &reg, sizeof(reg.buf), 0);
        printf("Mensagem enviada: %s\n", reg.buf);

        memset(&reg, 0, sizeof(reg));
    }
}
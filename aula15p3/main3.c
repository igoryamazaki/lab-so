#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

/*struct msg
{
    long key;
    char buf[10];
};*/
struct envelope
{
    long key;
    int num;
};

int main()
{
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    struct envelope reg;
    int pid = fork();
    int interacoes = 3;
    if (pid == 0)
    { // filho
        for (int i = 0; i < interacoes; i++)
        {
            reg.key = 1;
            msgrcv(id, &reg, sizeof(reg), 1, 0);
            printf("[Filho] Mensagem recebida: %d\n", reg.num);

            reg.num = reg.num * 2;
            reg.key = 2;
            msgsnd(id, &reg, sizeof(reg), 0);
            printf("[Filho] Mensagem enviada: %d\n", reg.num);
            memset(&reg, 0, sizeof(reg));
        }
    }
    else
    { // pai
        for (int i = 0; i < interacoes; i++)
        {
            reg.num = i + 2;
            reg.key = 1;
            msgsnd(id, &reg, sizeof(reg), 0);
            printf("[Pai] Mensagem enviada: %d\n", reg.num);
            memset(&reg, 0, sizeof(reg));

            reg.key = 2;
            msgrcv(id, &reg, sizeof(reg), 2, 0);
            printf("[Pai] Mensagem recebida: %d\n", reg.num);
        }
    }
}
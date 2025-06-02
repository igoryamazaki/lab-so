#include <stdio.h>
#include <stdlib.h>
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
    if (id == -1)
    {
        perror("Erro ao criar msg");
        return 1;
    }

    struct msg m;
    m.key = 1;
    strcpy(m.buf, "ABC");

    msgsnd(id, &m, sizeof(m.buf), 0);
    printf("Mensagem enviada: %s\n", m.buf);

    memset(&m, 0, sizeof(m));

    msgrcv(id, &m, sizeof(m.buf), 1, 0);
    printf("Mensagem recebida: %s\n", m.buf);
}
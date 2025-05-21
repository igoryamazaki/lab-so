#include <termios.h>
#include <stdio.h>
#include <unistd.h>

/*int main()
{
    struct termios reg;
    int c;

    tcgetattr(STDIN_FILENO, &reg);
    reg.c_lflag &= ~ICANON; // (desligando ICANON) mudando terminal para modo nao canonico

    c = getchar(); // lendo apenas um byte
    tcsetattr(STDIN_FILENO, TCSANOW, &reg);
    printf("\n%d\n", c);
}*/

int main()
{
    struct termios reg;
    int c;

    tcgetattr(STDIN_FILENO, &reg);
    reg.c_lflag &= ~ICANON; // (desligando ICANON) mudando terminal para modo nao canonico

    printf("Digite 's' para sair.\n");
    while (c != 's')
    {
        c = getchar();
        printf("\nVocê digitou: %c (ASCII: %d)\n", c, c);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &reg);
}
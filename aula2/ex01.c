#include <termios.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct termios reg;
    char str[50];
    tcgetattr(STDIN_FILENO, &reg);
    reg.c_lflag &= ~ICANON; // (desligando ICANON) mudando terminal para modo nao canonico
    tcsetattr(STDIN_FILENO, TCSANOW, &reg);

    printf("Digite uma string: ");
    scanf("%49s", str);
    printf("\n %s\n", str);
}
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main()
{
    struct termios old_settings, new_settings;
    char c;

    // Obtém e salva a configuração original do terminal
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;

    // **Modo Canônico** (padrão: espera ENTER)
    printf("Modo Canônico: Digite um caractere e pressione ENTER: ");
    fflush(stdout); // Garante que o texto apareça antes da entrada

    c = getchar(); // Lê um caractere no modo canônico
    printf("Você digitou: %c\n\n", c);

    // **Ativa Modo Não Canônico** (lê sem precisar pressionar ENTER)
    new_settings.c_lflag &= ~ICANON; // Desativa ICANON
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    printf("Modo Não Canônico: Digite um caractere (não precisa pressionar ENTER): ");
    fflush(stdout);

    read(STDIN_FILENO, &c, 1); // Lê um caractere sem esperar ENTER
    printf("\nVocê digitou: %c\n\n", c);

    // **Restaura o Modo Canônico**
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    printf("Modo Canônico restaurado.\n");

    return 0;
}

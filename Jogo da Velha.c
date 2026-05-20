#include <stdio.h>

char tabuleiro[3][3];

void iniciarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiro() {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ",
               tabuleiro[i][0],
               tabuleiro[i][1],
               tabuleiro[i][2]);

        if (i < 2)
            printf("\n---|---|---\n");
    }

    printf("\n\n");
}

int verificarVitoria() {

    for (int i = 0; i < 3; i++) {

        if (tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2] &&
            tabuleiro[i][0] != ' ')
            return 1;

        if (tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i] &&
            tabuleiro[0][i] != ' ')
            return 1;
    }

    if ((tabuleiro[0][0] == tabuleiro[1][1] &&
         tabuleiro[1][1] == tabuleiro[2][2] &&
         tabuleiro[0][0] != ' ') ||

        (tabuleiro[0][2] == tabuleiro[1][1] &&
         tabuleiro[1][1] == tabuleiro[2][0] &&
         tabuleiro[0][2] != ' '))
        return 1;

    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }

    return 1;
}

void jogar(char jogador) {

    int linha, coluna;

    do {
        printf("Jogador %c\n", jogador);

        printf("Digite linha (1-3): ");
        scanf("%d", &linha);

        printf("Digite coluna (1-3): ");
        scanf("%d", &coluna);

        linha--;
        coluna--;

        if (linha < 0 || linha > 2 ||
            coluna < 0 || coluna > 2 ||
            tabuleiro[linha][coluna] != ' ') {

            printf("\nPosicao invalida! Tente novamente.\n\n");

        } else {
            break;
        }

    } while (1);

    tabuleiro[linha][coluna] = jogador;
}

int main() {

    char jogador = 'X';

    iniciarTabuleiro();

    printf("===== JOGO DA VELHA =====\n");

    while (1) {

        mostrarTabuleiro();

        jogar(jogador);

        if (verificarVitoria()) {
            mostrarTabuleiro();
            printf("Parabens! Jogador %c venceu!\n", jogador);
            break;
        }

        if (verificarEmpate()) {
            mostrarTabuleiro();
            printf("Empate!\n");
            break;
        }

        if (jogador == 'X')
            jogador = 'O';
        else
            jogador = 'X';
    }

    return 0;
}
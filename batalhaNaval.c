#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int podePosicionar(int tabuleiro[10][10], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;

        if (novaLinha < 0 || novaLinha >= TAMANHO_TABULEIRO || novaColuna < 0 || novaColuna >= TAMANHO_TABULEIRO) {
            return 0; // fora dos limites
        }
        if (tabuleiro[novaLinha][novaColuna] != AGUA) {
            return 0; // já tem navio lá
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 1. Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar 4 navios

    // --- Navio Horizontal (linha 1, col 1)
    if (podePosicionar(tabuleiro, 1, 1, 0, 1)) {
        posicionarNavio(tabuleiro, 1, 1, 0, 1);
    }

    // --- Navio Vertical (linha 4, col 2)
    if (podePosicionar(tabuleiro, 4, 2, 1, 0)) {
        posicionarNavio(tabuleiro, 4, 2, 1, 0);
    }

    // --- Navio Diagonal (linha 0, col 6)
    if (podePosicionar(tabuleiro, 0, 6, 1, 1)) {
        posicionarNavio(tabuleiro, 0, 6, 1, 1);
    }

    // --- Navio Diagonal (linha 2, col 8)
    if (podePosicionar(tabuleiro, 2, 8, 1, -1)) {
        posicionarNavio(tabuleiro, 2, 8, 1, -1);
    }

    // 3. Exibir tabuleiro
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

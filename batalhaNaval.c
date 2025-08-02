#include <stdio.h>

// Tamanho fixo do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Criar o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 2. Inicializar tudo com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Criar dois navios (valores são simbólicos, tipo "3")
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // 4. Coordenadas de início (definidas direto no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // 5. Validar se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verificar se já tem outro navio lá
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                printf("Erro: Sobreposição de navios na horizontal!\n");
                return 1;
            }
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }

    // 6. Validar se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verificar se já tem outro navio lá
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                printf("Erro: Sobreposição de navios na vertical!\n");
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = navioVertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // 7. Exibir o tabuleiro
    printf("\n=== Tabuleiro de Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

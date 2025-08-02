#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para construir matriz de habilidade em cone
void construirCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2 - i) && j <= (TAMANHO_HABILIDADE / 2 + i)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para construir matriz de habilidade em cruz
void construirCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para construir matriz de habilidade em octaedro (losango)
void construirOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro com ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int matrizHabilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - offset + i;
            int colunaTabuleiro = origemColuna - offset + j;

            // Verificar se está dentro dos limites
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {

                if (matrizHabilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== Tabuleiro com Habilidades ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    tabuleiro[4][2] = NAVIO;
    tabuleiro[5][2] = NAVIO;
    tabuleiro[6][2] = NAVIO;

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 3, 7);      // Cone com origem em (3, 7)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);      // Cruz com origem em (6, 6)
    aplicarHabilidade(tabuleiro, octaedro, 2, 2);  // Octaedro com origem em (2, 2)

    // Exibir resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

// Verifica se é possível posicionar um navio sem sair do tabuleiro e sem sobreposição
bool pode_posicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] != AGUA) {
            return false;
        }
    }
    return true;
}

// Posiciona o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * d_linha][coluna + i * d_coluna] = OCUPADO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com água (0)

    // Coordenadas e direções dos navios
    // Navio horizontal
    int linha_h = 1, coluna_h = 4;
    if (pode_posicionar(tabuleiro, linha_h, coluna_h, 0, 1)) {
        posicionar_navio(tabuleiro, linha_h, coluna_h, 0, 1);
    }

    // Navio vertical
    int linha_v = 4, coluna_v = 2;
    if (pode_posicionar(tabuleiro, linha_v, coluna_v, 1, 0)) {
        posicionar_navio(tabuleiro, linha_v, coluna_v, 1, 0);
    }

    // Navio diagonal principal (↘)
    int linha_d1 = 0, coluna_d1 = 0;
    if (pode_posicionar(tabuleiro, linha_d1, coluna_d1, 1, 1)) {
        posicionar_navio(tabuleiro, linha_d1, coluna_d1, 1, 1);
    }

    // Navio diagonal secundária (↙)
    int linha_d2 = 2, coluna_d2 = 9;
    if (pode_posicionar(tabuleiro, linha_d2, coluna_d2, 1, -1)) {
        posicionar_navio(tabuleiro, linha_d2, coluna_d2, 1, -1);
    }

    // Imprime o cabeçalho das colunas (A a J)
    printf("    ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas (1 a 10)
    for (int linha = 0; linha < TAMANHO; linha++) {
        printf("%2d  ", linha + 1);
        for (int col = 0; col < TAMANHO; col++) {
            printf("%2d ", tabuleiro[linha][col]);
        }
        printf("\n");
    }

    return 0;
}

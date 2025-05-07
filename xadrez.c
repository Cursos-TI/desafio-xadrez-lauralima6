#include <stdio.h>

// Função recursiva para mover a Torre (horizontalmente para a direita)
void moverTorre(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// Função recursiva para mover a Rainha (horizontalmente para a esquerda)
void moverRainha(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// Função recursiva para mover o Bispo (combinando com loops aninhados para simular movimento diagonal)
void moverBispoRecursivo(int vertical, int horizontal) {
    if (vertical <= 0 || horizontal <= 0) return;

    for (int i = 0; i < vertical; i++) {
        for (int j = 0; j < horizontal; j++) {
            if (i == j) {
                printf("Cima Direita\n");
                break; // sai do loop interno após imprimir uma vez por linha
            }
        }
    }

    moverBispoRecursivo(vertical - 1, horizontal - 1); // movimento recursivo
}

// Função para simular o movimento do Cavalo em "L": duas casas para cima, uma para a direita
void moverCavalo() {
    printf("Movimento do Cavalo:\n");

    int movimentosExecutados = 0;

    for (int i = 0; i < 3; i++) { // controle geral de movimentos
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 1) {
                // movimento válido: 2 cima, 1 direita
                for (int k = 0; k < 2; k++) {
                    printf("Cima\n");
                }
                printf("Direita\n");
                movimentosExecutados++;
                break; // encerra o movimento após o primeiro "L" completo
            } else {
                continue; // ignora combinações que não formam "L"
            }
        }
        if (movimentosExecutados > 0) break; // sai do loop externo
    }
}

int main() {
    // Número de casas a serem percorridas
    int casasTorre = 5;
    int casasRainha = 8;
    int casasBispo = 5; // movimento de 5 casas diagonais (5 cima, 5 direita)

    // Movimento da Torre com recursividade
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    // Movimento do Bispo com recursividade e loops aninhados
    printf("\nMovimento do Bispo:\n");
    moverBispoRecursivo(casasBispo, casasBispo);

    // Movimento da Rainha com recursividade
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // Movimento complexo do Cavalo com loops aninhados
    printf("\n");
    moverCavalo();

    return 0;
}

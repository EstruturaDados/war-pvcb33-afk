#include <stdio.h>
#include <string.h>

#define TOTAL_TERRITORIOS 5

// Struct do território
typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

int main() {

    Territorio mapa[TOTAL_TERRITORIOS];

    // Cadastro dos territórios
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("\n=== Cadastro do Territorio %d ===\n", i + 1);

        printf("Nome do territorio: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exercito: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);

        getchar(); // limpa o ENTER do buffer
    }

    // Exibição do mapa
    printf("\n======= MAPA ATUAL =======\n");

    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {

        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }

    return 0;
}
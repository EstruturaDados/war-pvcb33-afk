#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_TERRITORIOS 5

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

void mostrarMapa(Territorio *mapa) {
    printf("\n======= MAPA =======\n");

    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("\n[%d] %s\n", i + 1, mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {

    int dadoAtaque = rand() % 6 + 1;
    int dadoDefesa = rand() % 6 + 1;

    printf("\n=== BATALHA ===\n");
    printf("Atacante (%s) tirou: %d\n", atacante->nome, dadoAtaque);
    printf("Defensor (%s) tirou: %d\n", defensor->nome, dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {

        defensor->tropas--;

        printf("\nO defensor perdeu 1 tropa!\n");

        if (defensor->tropas <= 0) {

            printf("\n%s conquistou %s!\n",
                   atacante->nome,
                   defensor->nome);

            strcpy(defensor->cor, atacante->cor);

            atacante->tropas--;
            defensor->tropas = 1;
        }

    } else {

        atacante->tropas--;

        printf("\nO atacante perdeu 1 tropa!\n");
    }
}

int main() {

    srand(time(NULL));

    Territorio *mapa =
        calloc(TOTAL_TERRITORIOS, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

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

        while (getchar() != '\n');
    }

    int atacante, defensor;
    char continuar;

    do {

        mostrarMapa(mapa);

        printf("\nEscolha o territorio atacante (1-%d): ",
               TOTAL_TERRITORIOS);
        scanf("%d", &atacante);

        printf("Escolha o territorio defensor (1-%d): ",
               TOTAL_TERRITORIOS);
        scanf("%d", &defensor);

        while (getchar() != '\n');

        if (atacante < 1 ||
            atacante > TOTAL_TERRITORIOS ||
            defensor < 1 ||
            defensor > TOTAL_TERRITORIOS ||
            atacante == defensor) {

            printf("\nEscolha invalida!\n");
        }
        else if (mapa[atacante - 1].tropas <= 1) {

            printf("\nO territorio atacante precisa ter mais de 1 tropa!\n");
        }
        else if (strcmp(mapa[atacante - 1].cor,
                         mapa[defensor - 1].cor) == 0) {

            printf("\nNao e permitido atacar um territorio aliado!\n");
        }
        else {

            atacar(&mapa[atacante - 1],
                   &mapa[defensor - 1]);
        }

        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &continuar);

        while (getchar() != '\n');

    } while (continuar == 's' || continuar == 'S');

    free(mapa);

    return 0;
}
#include <stdio.h>

int main() {
    int palo = 1;
    int valor;

    while (palo <= 5) {
        if (palo == 1)
            printf("\n=== Corazon ===\n");
        else if (palo == 2)
            printf("\n=== Diamante ===\n");
        else if (palo == 3)
            printf("\n=== Trebol ===\n");
        else if (palo == 4)
            printf("\n=== Picas ===\n");
        else if (palo==5)
            printf("\n=== Estrellas ===\n");

        for (valor = 3; valor <= 13; valor++) {
            if (valor == 11)
                printf("J ");
            else if (valor == 12)
                printf("Q ");
            else if (valor == 13)
                printf("K ");
            else
                printf("%d ", valor);
        }
        printf("\n");
        palo++;
    }
}
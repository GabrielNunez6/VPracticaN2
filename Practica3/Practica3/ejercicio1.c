#include <stdio.h>

int main() {
    int palo = 1;
    int valor;

    while (palo <= 4) {
        for (valor = 1; valor <= 13; valor++) {
            if (valor == 1)
                printf("A de ");
            else if (valor == 11)
                printf("J de ");
            else if (valor == 12)
                printf("Q de ");
            else if (valor == 13)
                printf("K de ");
            else
                printf("%d de ", valor);
            if (palo == 1)
                printf("Corazon\n");
            else if (palo == 2)
                printf("Diamante\n");
            else if (palo == 3)
                printf("Trebol\n");
            else if (palo == 4)
                printf("Picas\n");
        }
        palo++;
    }

    return 0;
}
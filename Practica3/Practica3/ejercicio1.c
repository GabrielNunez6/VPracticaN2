#include <stdio.h>

int main() {
    int palo, valor;

    for (palo = 1; palo <= 4; palo++) {
        switch (palo) {
            case 1:
                printf("=== Corazones ===\n");
                break;
            case 2:
                printf("=== Diamantes ===\n");
                break;
            case 3:
                printf("=== Treboles ===\n");
                break;
            case 4:
                printf("=== Picas ===\n");
                break;
        }
        for (valor = 1; valor <= 13; valor++) {

            switch (valor) {
                case 1:
                    printf("A ");
                    break;
                case 11:
                    printf("J ");
                    break;
                case 12:
                    printf("Q ");
                    break;
                case 13:
                    printf("K ");
                    break;
                default:
                    printf("%d ", valor);
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int dado = lanzarDado();
    printf("El dado cayo en: %d\n", dado);
    switch (dado) {
        case 1:
        case 2:
        case 3:
            printf("*\n");
            break;
        case 4:
            printf("L\n");
            break;
        case 5:
            printf("C\n");
            break;
        case 6:
            printf("R\n");
            break;
        default:
            printf("ese valor de dado no existe");
    }

    return 0;
}
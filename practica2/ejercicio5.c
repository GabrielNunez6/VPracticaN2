#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int dado = lanzarDado();
    char simbolo;
    printf("El dado cayo en: %d ", dado);
    switch (dado) {
        case 1:
        case 2:
        case 3:
            simbolo = '*';
            break;
        case 4:
            simbolo = 'L';
            break;
        case 5:
            simbolo = 'C';
            break;
        case 6:
            simbolo = 'R';
            break;
        default:
            printf("ese valor de dado no existe");
    }
    printf("\nSimbolo convertido: %c\n", simbolo);
    return 0;
}
//
// Created by usuario on 4/8/2025.
//
#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int dado1=lanzarDado();
    int dado2=lanzarDado();
    int dado3=lanzarDado();

    int mayor = dado1;
    if (dado2>mayor)
        mayor = dado2;
    if (dado3>mayor)
        mayor = dado3;

    printf("Los 3 dados lanzados fueron: %d, %d, %d\n", dado1, dado2, dado3);
    printf("El dado mayor es: %d\n", mayor);

    return 0;
}
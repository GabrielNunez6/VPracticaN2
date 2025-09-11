#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int d1 = lanzarDado();
    int d2 = lanzarDado();
    int d3 = lanzarDado();
    int temporal;
    printf("Dados obtenidos: %d, %d, %d\n", d1, d2, d3);
    if (d1 < d2) {
        temporal = d1;
        d1 = d2;
        d2 = temporal; }
    if (d1 < d3) {
        temporal = d1;
        d1 = d3;
        d3 = temporal;
    }
    if (d2 < d3) {
        temporal = d2;
        d2 = d3;
        d3 = temporal;
    }

    printf("Orden descendente: %d, %d, %d\n", d1, d2, d3);

    return 0;
}
#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int dado1=lanzarDado();
    int dado2=lanzarDado();
    printf("el dado 1 es %d",dado1);
    printf("\n");
    printf("el dado 2 es %d\n",dado2);
    if(dado1==dado2) {
        printf("Eres un ganador!!\n");
    } else {
        printf("Perdiste:(\n");
    }
    return 0;
}
#include <stdio.h>
#include "aleatorio.h"
#include "BarajaInglesa.h"
#define CARTAS 52

int main() {
    initAleatorio();
    Carta mazo[CARTAS];

    llenarYMezclarBaraja(mazo, CARTAS);

    printf("10 cartas del mazo:\n");
    for (int i = 0; i < 10; i++) {
        printf("Carta %d: %d de %c\n", i+1, mazo[i].valor, mazo[i].palo);
    }

    return 0;
}
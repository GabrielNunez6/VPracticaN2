#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();

    int fours[4], fives[4], sixes[4];
    int straights[4], fullHouse[4], choice[4];
    int baluts;
    int i;
    int s = numeroAleatorioConRango(0, 3);

    for (i = 0; i < 4; i++) {
        fours[i] = numeroAleatorioConRango(0, 6) * 4;
        fives[i] = numeroAleatorioConRango(0, 6) * 5;
        sixes[i] = numeroAleatorioConRango(0, 6) * 6;

        //s == 1 - una escalera pequeña (small straight) vale 15 puntos.
        //s == 2 - una escalera grande (large straight) vale 20 puntos.
        // s == 0 - ninguna escalera, entonces 0 puntos.
        if (s == 1)
            straights[i] = 15;
        else if (s == 2)
            straights[i] = 20;
        else
            straights[i] = 0;

        //Se genera si hubo un Full House (tieneFull = 1) o no (tieneFull = 0).
        //Si sí hubo, se le asigna un puntaje entre 10 y 30.
        int tieneFull = numeroAleatorioConRango(0, 2);//
        if (tieneFull)
            fullHouse[i] = numeroAleatorioConRango(10, 31);
        else
            fullHouse[i] = 0;

        choice[i] = numeroAleatorioConRango(5, 31);//Choice se suman los valores de todos los dados, así que puede ser cualquier número de 5 a 30.
    }

    baluts = numeroAleatorioConRango(0, 5);
}
#include <stdio.h>
#include "jugador.h"

void repartirFichas(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice) {
    int i;
    for(i = 0; i < numJugadores; i++){
        while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas){
            jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
            jugadores[i].numFichas++;
            bancoIndice++;
        }
    }
}

void mostrarManos(Jugador jugadores[], int numJugadores) {
    int i, j;
    for(i=0;i<numJugadores;i++){
        printf("Jugador %d: ", i+1);
        for(j=0;j<jugadores[i].numFichas;j++){
            printf("[%d|%d] ", jugadores[i].mano[j].lado1,jugadores[i].mano[j].lado2);
        }
        printf("\n");
    }
}

int suma20(Domino a, Domino b) {
    int ladosA[2] = {a.lado1, a.lado2};
    int ladosB[2] = {b.lado1, b.lado2};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int valA = ladosA[i]==0 ? 20-ladosB[j] : ladosA[i];
            int valB = ladosB[j]==0 ? 20-ladosA[i] : ladosB[j];
            if(valA+valB==20) return 1;
        }
    }
    return 0;
}

void descartarParejas(Jugador jugadores[], int numJugadores) {
    int p, i, j;
    for(p = 0; p < numJugadores; p++) {
        int usado[MAX_FICHAS_JUGADOR] = {0};

        for(i = 0; i < jugadores[p].numFichas; i++) {
            if(usado[i] == 0){
                for(j = i + 1; j < jugadores[p].numFichas; j++) {
                    if(usado[j] == 0){
                        if(suma20(jugadores[p].mano[i], jugadores[p].mano[j]) == 1) {
                            printf("Jugador %d descarta pareja: [%d|%d] y [%d|%d]\n",
                                   p + 1,
                                   jugadores[p].mano[i].lado1, jugadores[p].mano[i].lado2,
                                   jugadores[p].mano[j].lado1, jugadores[p].mano[j].lado2);
                            usado[i] = 1;
                            usado[j] = 1;
                            break;
                        }
                    }
                }
            }
        }

        // Reconstruir la mano
        Domino nuevaMano[MAX_FICHAS_JUGADOR];
        int idx = 0;
        for(i = 0; i < jugadores[p].numFichas; i++){
            if(usado[i] == 0){
                nuevaMano[idx] = jugadores[p].mano[i];
                idx++;
            }
        }
        jugadores[p].numFichas = idx;
        for(i=0;i<idx;i++)
            jugadores[p].mano[i] = nuevaMano[i];
    }
}
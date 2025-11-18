//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include "jugador.h"
#include "aleatorio.h"
#include "domino.h"

/*
 * Repartir fichas a los jugadores de manera equitativa
 */
void repartirFichas(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas) {
    int indice = 0;

    // Cada jugador recibe 6 fichas
    for(int i = 0; i < numJugadores; i++) {
        jugadores[i].numFichas = 0; // Inicializar número de fichas
        for(int j = 0; j < 6; j++) {
            if(indice < totalFichas) {
                jugadores[i].mano[jugadores[i].numFichas] = mazo[indice];
                jugadores[i].numFichas++;
                indice++;
            }
        }
    }
}


/*
 * Mostrar la mano de cada jugador
 */
void mostrarManos(Jugador jugadores[], int numJugadores) {
    for(int i = 0; i < numJugadores; i++) {
        printf("Jugador %d: ", i + 1);
        for(int j = 0; j < jugadores[i].numFichas; j++) {
            printf("[%d|%d] ", jugadores[i].mano[j].lado1, jugadores[i].mano[j].lado2);
        }
        printf("\n");
    }
}

/*
 * Verifica si dos fichas suman 20 considerando comodines (0)
 */
int suma20(Domino a, Domino b) {
    int ladosA[2] = {a.lado1, a.lado2};
    int ladosB[2] = {b.lado1, b.lado2};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int valA = ladosA[i];
            int valB = ladosB[j];

            if(valA == 0) valA = 20 - valB;
            if(valB == 0) valB = 20 - valA;

            if(valA + valB == 20) return 1;
        }
    }
    return 0;
}

/*
 * Descarta todas las parejas que sumen 20 en los jugadores
 * Aquí usamos solo arrays, no punteros
 */
void descartarParejas(Jugador jugadores[], int numJugadores) {
    for(int p = 0; p < numJugadores; p++) {
        int usado[MAX_FICHAS_JUGADOR] = {0};

        for(int i = 0; i < jugadores[p].numFichas; i++) {
            if(usado[i]) continue;
            for(int j = i + 1; j < jugadores[p].numFichas; j++) {
                if(usado[j]) continue;

                if(suma20(jugadores[p].mano[i], jugadores[p].mano[j])) {
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

        // Reconstruir la mano sin las fichas descartadas
        Domino nuevaMano[MAX_FICHAS_JUGADOR];
        int idx = 0;
        for(int i = 0; i < jugadores[p].numFichas; i++) {
            if(!usado[i]) {
                nuevaMano[idx++] = jugadores[p].mano[i];
            }
        }
        jugadores[p].numFichas = idx;
        for(int i = 0; i < idx; i++) {
            jugadores[p].mano[i] = nuevaMano[i];
        }
    }
}
#include <stdio.h>
#include "jugador.h"
#include "domino.h"
#include "turnos.h"
#include "ganador.h"
#include "registroPartida.h"
#include <string.h>

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

void mostrarMano(Jugador jugador) {
    printf("Fichas en mano: ");
    for(int i=0; i<jugador.numFichas; i++){
        printf("[%d|%d] ", jugador.mano[i].lado1, jugador.mano[i].lado2);
    }
    printf("\n");
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
    int posiblesA[2] = {a.lado1, a.lado2};
    int posiblesB[2] = {b.lado1, b.lado2};

    // Revisar todas las combinaciones posibles
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int valA = posiblesA[i];
            int valB = posiblesB[j];

            // Si es comodín, toma el valor que complete 20
            if(valA == 0) valA = 20 - valB;
            if(valB == 0) valB = 20 - valA;

            if(valA + valB == 20) return 1;
        }
    }

    return 0;
}

int descartarParejas(Jugador jugadores[], int indiceJugador, char nombreArchivo[]) {
    Jugador jugador = jugadores[indiceJugador];
    int usado[12] = {0};
    int descarto = 0;

    for(int i = 0; i < jugador.numFichas; i++) {
        if(usado[i]) continue;

        for(int j = i + 1; j < jugador.numFichas; j++) {
            if(usado[j]) continue;

            if(suma20(jugador.mano[i], jugador.mano[j])) {
                printf("Jugador %s descarta pareja: [%d|%d] + [%d|%d]\n",
                       jugador.nombre,
                       jugador.mano[i].lado1, jugador.mano[i].lado2,
                       jugador.mano[j].lado1, jugador.mano[j].lado2);

                RegistroPar r;
                snprintf(r.nombreJugador, sizeof(r.nombreJugador), "%s", jugador.nombre);
                r.lado1 = jugador.mano[i].lado1;
                r.lado2 = jugador.mano[i].lado2;
                r.lado3 = jugador.mano[j].lado1;
                r.lado4 = jugador.mano[j].lado2;
                guardarPar(r, nombreArchivo);

                usado[i] = 1;
                usado[j] = 1;
                descarto = 1;
                break;
            }
        }
    }

    // Reconstruir la mano sin las fichas descartadas
    Domino nuevaMano[12];
    int idx = 0;
    for(int i = 0; i < jugador.numFichas; i++) {
        if(!usado[i]) {
            nuevaMano[idx] = jugador.mano[i];
            idx++;
        }
    }

    for(int i = 0; i < idx; i++) {
        jugadores[indiceJugador].mano[i] = nuevaMano[i];
    }
    jugadores[indiceJugador].numFichas = idx;

    return descarto;
}
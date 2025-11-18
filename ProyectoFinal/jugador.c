#include <stdio.h>
#include "jugador.h"
#include "domino.h"
#include "turnos.h"
#include "ganador.h"
#include "registroPartida.h"
#include <string.h>

/*
 * Función: repartirFichas
 * -----------------------
 * Reparte 6 fichas a cada jugador desde el mazo, comenzando en el índice bancoIndice.
 * @param
 * jugadores: arreglo de jugadores que recibirán fichas
 * numJugadores: cantidad de jugadores en la partida
 * mazo: arreglo que contiene todas las fichas del domino
 * totalFichas: número total de fichas en el mazo
 * bancoIndice: índice de la primera ficha disponible en el mazo
 *
 * Devuelve: void
 */
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

/*
 * Función: mostrarMano
 * --------------------
 * Imprime en consola todas las fichas que tiene un jugador.
 * @param
 * jugador: estructura Jugador cuya mano se mostrará
 */
void mostrarMano(Jugador jugador) {
    printf("Fichas en mano: ");
    for(int i=0; i<jugador.numFichas; i++){
        printf("[%d|%d] ", jugador.mano[i].lado1, jugador.mano[i].lado2);
    }
    printf("\n");
}

/*
 * Función: mostrarManos
 * ---------------------
 * Muestra las manos de todos los jugadores en la partida.
 * @paaram
 * jugadores: arreglo de jugadores
 * numJugadores: número de jugadores
 */
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

/*
 * Función: suma20
 * ----------------
 * Determina si dos fichas pueden formar un par que sume 20, considerando comodines (0).
 * @param
 * a, b: fichas a evaluar
 *
 * Devuelve: 1 si las fichas forman 20, 0 si no
 */
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

/*
 * Función: descartarParejas
 * -------------------------
 * Recorre la mano de un jugador buscando pares que sumen 20.
 * Guarda el par en un archivo de registro de la partida y remueve las fichas descartadas.
 * @param
 * jugadores: arreglo de jugadores
 * indiceJugador: índice del jugador a evaluar
 * nombreArchivo: archivo binario donde se guardan los pares formados
 *
 * Devuelve: 1 si se descartó al menos un par, 0 si no
 */
int descartarParejas(Jugador jugadores[], int indiceJugador, char nombreArchivo[]) {
    Jugador jugador = jugadores[indiceJugador];
    int usado[12] = {0}; // Marcador de fichas descartadas
    int descarto = 0;

    for(int i = 0; i < jugador.numFichas; i++) {
        if(usado[i]) continue;

        for(int j = i + 1; j < jugador.numFichas; j++) {
            if(usado[j]) continue;

            // Verificar si la combinación suma 20
            if(suma20(jugador.mano[i], jugador.mano[j])) {
                printf("Jugador %s descarta pareja: [%d|%d] + [%d|%d]\n",
                       jugador.nombre,
                       jugador.mano[i].lado1, jugador.mano[i].lado2,
                       jugador.mano[j].lado1, jugador.mano[j].lado2);

                // Guardar par en el registro de la partida
                RegistroPar r;
                strncpy(r.nombreJugador, jugador.nombre, sizeof(r.nombreJugador) - 1);
                r.nombreJugador[sizeof(r.nombreJugador) - 1] = '\0';
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
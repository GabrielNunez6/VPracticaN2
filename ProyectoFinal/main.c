#include <stdio.h>
#include <stdlib.h>
#include "aleatorio.h"

#define MAX_JUGADORES 4
#define MAX_FICHAS 91  // Suficiente para doble 12

typedef struct {
    int lado1;
    int lado2;
} Domino;

typedef struct {
    Domino mano[28]; // Cada jugador puede tener hasta 28 fichas
    int numFichas;
} Jugador;

Domino mazo[MAX_FICHAS];
int totalFichas = 0;

// Función para crear el mazo aleatoriamente
void crearMazo(int tipo_domino) {
    totalFichas = 0;
    for(int i = 0; i <= tipo_domino; i++) {
        for(int j = i; j <= tipo_domino; j++) {
            mazo[totalFichas].lado1 = i; // O usa generaLadoFicha() si quieres más aleatorio
            mazo[totalFichas].lado2 = j;
            totalFichas++;
        }
    }
}

// Mezclar el mazo usando numeroAleatorio()
void mezclarMazo() {
    for(int i = 0; i < totalFichas; i++) {
        int r = numeroAleatorio(totalFichas);
        Domino temp = mazo[i];
        mazo[i] = mazo[r];
        mazo[r] = temp;
    }
}

// Repartir fichas a los jugadores
void repartirFichas(Jugador jugadores[], int numJugadores) {
    int indice = 0;
    while(indice < totalFichas) {
        for(int i = 0; i < numJugadores; i++) {
            if(indice < totalFichas) {
                jugadores[i].mano[jugadores[i].numFichas] = mazo[indice];
                jugadores[i].numFichas++;
                indice++;
            }
        }
    }
}

// Mostrar manos de los jugadores
void mostrarManos(Jugador jugadores[], int numJugadores) {
    for(int i = 0; i < numJugadores; i++) {
        printf("Jugador %d: ", i+1);
        for(int j = 0; j < jugadores[i].numFichas; j++) {
            printf("[%d|%d] ", jugadores[i].mano[j].lado1, jugadores[i].mano[j].lado2);
        }
        printf("\n");
    }
}

int main() {
    initAleatorio();

    int numJugadores, tipoDomino;

    printf("Numero de jugadores (1-4): ");
    scanf("%d", &numJugadores);
    if(numJugadores < 1 || numJugadores > 4) {
        printf("Número de jugadores inválido.\n");
        return 1;
    }

    printf("Tipo de domino (6, 9 o 12): ");
    scanf("%d", &tipoDomino);
    if(tipoDomino != 6 && tipoDomino != 9 && tipoDomino != 12) {
        printf("Tipo de domino inválido.\n");
        return 1;
    }

    Jugador jugadores[MAX_JUGADORES];
    for(int i = 0; i < numJugadores; i++)
        jugadores[i].numFichas = 0;

    crearMazo(tipoDomino);
    mezclarMazo();
    repartirFichas(jugadores, numJugadores);
    mostrarManos(jugadores, numJugadores);

    return 0;
}
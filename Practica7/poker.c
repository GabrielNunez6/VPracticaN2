#include <stdio.h>
#include "BarajaInglesa.h"
#include "Poker3Card.h"

#define MAX_JUGADORES 4
#define TAMANO_MANO 3

int main() {
    initAleatorio();
    printf("=== POKER DE 3 CARTAS===\n");

    int numJugadores;
    do {
        printf("Cuantos jugadores participaran? (1-4): ");
        scanf("%d", &numJugadores);
        if (numJugadores < 1 || numJugadores > MAX_JUGADORES) {
            printf("Ingresa un valor entre 1 y 4.\n");
        }
    } while (numJugadores < 1 || numJugadores > MAX_JUGADORES);

    Jugador jugadores[MAX_JUGADORES];
    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].id = i + 1;
        jugadores[i].saldo = 300;
        jugadores[i].rondasJugadas = 0;
    }
    Jugador dealer;
    Carta mazo[52];
    char continuar = 's';


    while (continuar == 's') {
        printf("\n--- SIGUIENTE RONDA ---\n");
        llenarYMezclarBaraja(mazo, 52);

        int contador = 0;

        for (int i = 0; i < numJugadores; i++) {
            for (int j = 0; j < TAMANO_MANO; j++) {
                jugadores[i].cartas[j] = mazo[contador++];
            }
        }
    }
}
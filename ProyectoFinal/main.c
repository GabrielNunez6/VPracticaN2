#include <stdio.h>
#include <stdlib.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"
#include "turnos.h"

#define MAX_JUGADORES 4
#define MAX_FICHAS 91
#define ARCHIVO_BINARIO "partida_lucky20.dat"

int main() {
    initAleatorio();

    int numJugadores, tipoDomino;

    printf("Número de jugadores (1-4): ");
    scanf("%d", &numJugadores);
    if(numJugadores < 1 || numJugadores > MAX_JUGADORES) {
        printf("Número de jugadores inválido.\n");
        return 1;
    }

    printf("Tipo de dominó (6, 9 o 12): ");
    scanf("%d", &tipoDomino);
    if(tipoDomino != 6 && tipoDomino != 9 && tipoDomino != 12) {
        printf("Tipo de dominó inválido.\n");
        return 1;
    }

    Domino mazo[MAX_FICHAS];
    int totalFichas = crearMazo(mazo, tipoDomino);
    mezclarMazo(mazo, totalFichas);

    Jugador jugadores[MAX_JUGADORES];
    for(int i=0; i<numJugadores; i++)
        jugadores[i].numFichas = 0;

    int bancoIndice = 0;

    // Reparto inicial de 6 fichas por jugador
    repartirFichas(jugadores, numJugadores, mazo, totalFichas, bancoIndice);

    // Llamada al juego interactivo
    bancoIndice = jugarTurnos(jugadores, numJugadores, mazo, totalFichas, bancoIndice);

    // Guardar partida en archivo binario
    FILE *archivo = fopen(ARCHIVO_BINARIO, "wb");
    if(archivo != NULL) {
        fwrite(&numJugadores, sizeof(int), 1, archivo);
        for(int i = 0; i < numJugadores; i++) {
            fwrite(&jugadores[i].numFichas, sizeof(int), 1, archivo);
            fwrite(jugadores[i].mano, sizeof(Domino), jugadores[i].numFichas, archivo);
        }
        fclose(archivo);
        printf("Partida guardada en '%s'\n", ARCHIVO_BINARIO);
    } else {
        printf("Error al guardar la partida.\n");
    }

    return 0;
}
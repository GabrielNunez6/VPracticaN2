#include <stdio.h>
#include <stdlib.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"

#define MAX_JUGADORES 4
#define MAX_FICHAS 91
#define ARCHIVO_BINARIO "partida_lucky20.dat"

int main() {
    initAleatorio();

    int numJugadores, tipoDomino;

    printf("Número de jugadores (1-4): ");
    scanf("%d", &numJugadores);
    if(numJugadores < 1 || numJugadores > 4) {
        printf("Número de jugadores inválido.\n");
        return 1;
    }

    printf("Tipo de dominó (6, 9 o 12): ");
    scanf("%d", &tipoDomino);
    if(tipoDomino != 6 && tipoDomino != 9 && tipoDomino != 12) {
        printf("Tipo de dominó inválido.\n");
        return 1;
    }

    // Crear y mezclar mazo
    Domino mazo[MAX_FICHAS];
    int totalFichas = crearMazo(mazo, tipoDomino);
    mezclarMazo(mazo, totalFichas);

    // Crear jugadores
    Jugador jugadores[MAX_JUGADORES];
    int i, j;
    for(i = 0; i < numJugadores; i++)
        jugadores[i].numFichas = 0;

    int bancoIndice = 0;

    // Reparto inicial: 6 fichas por jugador
    for(i = 0; i < numJugadores; i++) {
        while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas) {
            jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
            jugadores[i].numFichas++;
            bancoIndice++;
        }
    }

    int juegoTerminado = 0;
    while(juegoTerminado == 0) {
        printf("\n--- Manos actuales ---\n");
        mostrarManos(jugadores, numJugadores);

        // Descartar parejas sumando 20
        descartarParejas(jugadores, numJugadores);

        // Reponer hasta 6 fichas por jugador
        for(i = 0; i < numJugadores; i++) {
            while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas) {
                jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
                jugadores[i].numFichas++;
                bancoIndice++;
            }
        }

        // Comprobar ganador
        int hayGanador = 0;
        for(i = 0; i < numJugadores; i++) {
            if(jugadores[i].numFichas == 0) {
                printf("\n¡El jugador %d se quedó sin fichas y gana el juego!\n", i + 1);
                juegoTerminado = 1;
                hayGanador = 1;
            }
        }

        // Fin si no hay fichas en banco y nadie puede jugar
        if(juegoTerminado == 0) {
            int fichasRestantes = 0;
            for(i = 0; i < numJugadores; i++)
                fichasRestantes += jugadores[i].numFichas;
            if(fichasRestantes == 0) {
                printf("\n¡Todos los jugadores se quedaron sin fichas! Empate.\n");
                juegoTerminado = 1;
            }
        }
    }

    // Guardar la partida en archivo binario
    FILE *archivo = fopen(ARCHIVO_BINARIO, "wb");
    if(archivo != NULL) {
        fwrite(&numJugadores, sizeof(int), 1, archivo);
        for(i = 0; i < numJugadores; i++) {
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
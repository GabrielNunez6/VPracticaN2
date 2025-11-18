//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"
#include "turnos.h"
#include "registroPartida.h"
#include "ganador.h"

int menuPrincipal() {
    int opcion;
    printf("\n=== LUCKY 20 ===\n");
    printf("1) Jugar nueva partida\n");
    printf("2) Consultar historial de ganadores\n");
    printf("3) Reproducir partida guardada\n");
    printf("4) Salir\n");
    printf("Seleccione opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int configurarModoPrueba(Jugador jugadores[], int numJugadores, Domino mazo[], int bancoIndice) {
    // Jugador 0 recibe fichas que garantizan formar un par
    jugadores[0].mano[0] = (Domino){10,10};
    jugadores[0].mano[1] = (Domino){10,10};
    jugadores[0].numFichas = 2;

    // Reparto normal para los demás jugadores
    for(int i = 1; i < numJugadores; i++){
        while(jugadores[i].numFichas < 6 && bancoIndice < MAX_FICHAS){
            jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
            jugadores[i].numFichas++;
            bancoIndice++;
        }
    }
    return bancoIndice; // devolvemos el índice actualizado
}

void jugarPartida(int modoPrueba) {
    int numJugadores, tipoDomino;
    printf("Numero de jugadores (1-4): ");
    scanf("%d", &numJugadores);
    printf("Tipo de domino (6,9,12): ");
    scanf("%d", &tipoDomino);

    Domino mazo[MAX_FICHAS];
    int totalFichas = crearMazo(mazo, tipoDomino);
    mezclarMazo(mazo, totalFichas);

    Jugador jugadores[MAX_JUGADORES];
    for(int i = 0; i < numJugadores; i++){
        jugadores[i].numFichas = 0;
        sprintf(jugadores[i].nombre, "Jugador %d", i+1);
    }

    int bancoIndice = 0;
    char nombreArchivoPartida[100];
    generarNombreArchivo(nombreArchivoPartida);
    printf("Archivo de la partida: %s\n", nombreArchivoPartida);

    if(modoPrueba){
        bancoIndice = configurarModoPrueba(jugadores, numJugadores, mazo, bancoIndice);
    } else {
        // reparto normal
        for(int i = 0; i < numJugadores; i++){
            while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas){
                jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
                jugadores[i].numFichas++;
                bancoIndice++;
            }
        }
    }

    bancoIndice = jugarTurnos(jugadores, numJugadores, mazo, totalFichas, bancoIndice, nombreArchivoPartida);
}

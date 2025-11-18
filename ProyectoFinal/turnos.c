//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "turnos.h"
#include "jugador.h"
#include "ganador.h"
#include "registroPartida.h"

// Función auxiliar: verifica si un jugador puede formar un par
int puedeFormarPar(Jugador jugador) {
    for(int i=0;i<jugador.numFichas;i++){
        for(int j=i+1;j<jugador.numFichas;j++){
            if(suma20(jugador.mano[i], jugador.mano[j])) return 1;
        }
    }
    return 0;
}

int jugarTurnos(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice, char nombreArchivo[]) {
    int juegoTerminado = 0;

    while(!juegoTerminado) {
        for(int p = 0; p < numJugadores; p++) {
            if(jugadores[p].numFichas == 0) continue; // jugador sin fichas ya ganó o se retiró

            printf("\n--- Turno del jugador: %s ---\n", jugadores[p].nombre);
            // Mostrar la mano del jugador
            printf("Fichas en mano: ");
            for(int f=0; f<jugadores[p].numFichas; f++) {
                printf("[%d|%d] ", jugadores[p].mano[f].lado1, jugadores[p].mano[f].lado2);
            }
            printf("\nFichas en banco: %d\n", totalFichas - bancoIndice);

            // Intentar descartar un par automáticamente
            int parFormado = descartarParejas(jugadores, p, nombreArchivo);
            if(parFormado) {
                printf("Se descartó un par automáticamente.\n");
                if(jugadores[p].numFichas == 0) {
                    printf("¡El jugador %s se queda sin fichas y gana la partida!\n", jugadores[p].nombre);
                    registrarGanador(jugadores[p], "historialGanadores.bin");
                    juegoTerminado = 1;
                    break;
                }
            } else {
                // No hay pares disponibles
                printf("No se pueden formar más pares.\n");
                printf("Accion: 1) Formar par 2) Pedir 4 fichas 3) Retirarse: ");
                int accion;
                scanf("%d", &accion);

                if(accion == 1) {
                    printf("No hay pares disponibles, elige otra acción.\n");
                } else if(accion == 2) {
                    // Tomar hasta 4 fichas del banco
                    int tomadas = 0;
                    while(jugadores[p].numFichas < 12 && bancoIndice < totalFichas && tomadas < 4) {
                        jugadores[p].mano[jugadores[p].numFichas] = mazo[bancoIndice];
                        jugadores[p].numFichas++;
                        bancoIndice++;
                        tomadas++;
                    }
                    printf("Jugador %s toma %d fichas del banco.\n", jugadores[p].nombre, tomadas);
                } else if(accion == 3) {
                    printf("Jugador %s se retira de la partida.\n", jugadores[p].nombre);
                    jugadores[p].numFichas = 0;
                }
            }
        }

        // Verificar si aún quedan pares posibles o fichas en banco
        int quedanPares = 0;
        for(int p=0; p<numJugadores; p++) {
            if(jugadores[p].numFichas > 0) {
                if(descartarParejas(jugadores, p, nombreArchivo)) {
                    quedanPares = 1;
                    break;
                }
            }
        }

        if(!quedanPares && bancoIndice >= totalFichas) {
            printf("\nNo quedan pares posibles y se agotó el banco. Todos pierden.\n");
            juegoTerminado = 1;
        }
    }

    return bancoIndice;
}



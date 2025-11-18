//
// Created by usuario on 11/17/2025.
//
// turnos.c
// Funciones que manejan los turnos de los jugadores en Lucky 20.
// Incluye verificar si se puede formar un par y ejecutar los turnos
// de los jugadores hasta que alguien gane o todos pierdan.

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "turnos.h"
#include "jugador.h"
#include "ganador.h"
#include "registroPartida.h"

// ------------------------
// Función: puedeFormarPar
// Verifica si un jugador puede formar un par que sume 20 con sus fichas.
// Parámetros:
//   jugador: estructura Jugador con sus fichas
// Retorna:
//   1 si puede formar un par, 0 si no
// ------------------------
int puedeFormarPar(Jugador jugador) {
    for(int i = 0; i < jugador.numFichas; i++){
        for(int j = i + 1; j < jugador.numFichas; j++){
            if(suma20(jugador.mano[i], jugador.mano[j]))
                return 1; // Existe al menos un par que suma 20
        }
    }
    return 0; // No hay pares posibles
}

// ------------------------
// Función: jugarTurnos
// Ejecuta la mecánica de turnos del juego Lucky 20 hasta que alguien gane
// o todos pierdan. Maneja la lógica de descartar pares, pedir fichas
// o retirarse.
// Parámetros:
//   jugadores: arreglo de jugadores activos
//   numJugadores: cantidad de jugadores
//   mazo: arreglo con todas las fichas del mazo
//   totalFichas: total de fichas en el mazo
//   bancoIndice: índice de la siguiente ficha disponible en el banco
//   nombreArchivo: archivo donde se registran los pares formados
// Retorna:
//   índice actualizado del banco (bancoIndice) al final de la partida
// ------------------------
int jugarTurnos(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice, char nombreArchivo[]) {
    int juegoTerminado = 0;

    // Ciclo principal del juego
    while(!juegoTerminado) {
        for(int p = 0; p < numJugadores; p++) {
            if(jugadores[p].numFichas == 0)
                continue; // Saltar jugador que ya ganó o se retiró

            printf("\n--- Turno del jugador: %s ---\n", jugadores[p].nombre);

            // Mostrar la mano actual
            printf("Fichas en mano: ");
            for(int f = 0; f < jugadores[p].numFichas; f++)
                printf("[%d|%d] ", jugadores[p].mano[f].lado1, jugadores[p].mano[f].lado2);
            printf("\nFichas en banco: %d\n", totalFichas - bancoIndice);

            // Intentar descartar pares automáticamente
            int parFormado = descartarParejas(jugadores, p, nombreArchivo);

            if(parFormado) {
                printf("Se descartó un par automáticamente.\n");

                // Verificar si el jugador se quedó sin fichas (gana)
                if(jugadores[p].numFichas == 0) {
                    printf("El jugador %s se queda sin fichas y gana la partida!\n", jugadores[p].nombre);
                    registrarGanador(jugadores[p], "historialGanadores.bin");
                    juegoTerminado = 1;
                    break; // Salir del for de jugadores
                }
            } else {
                // No hay pares automáticos, pedir acción del jugador
                int accion = 0;
                int hayPar = 0;

                do {
                    printf("No se pueden formar más pares.\n");
                    printf("Accion: 1) Formar par 2) Pedir 4 fichas 3) Retirarse: ");
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

                        // Verificar si con las nuevas fichas puede descartar pares
                        hayPar = descartarParejas(jugadores, p, nombreArchivo);
                        if(hayPar) {
                            printf("Se descartó un par automáticamente tras tomar fichas.\n");
                            if(jugadores[p].numFichas == 0) {
                                printf("El jugador %s se queda sin fichas y gana la partida!\n", jugadores[p].nombre);
                                registrarGanador(jugadores[p], "historialGanadores.bin");
                                juegoTerminado = 1;
                                break;
                            }
                        }
                    } else if(accion == 3) {
                        // Retirarse
                        printf("Jugador %s se retira de la partida.\n", jugadores[p].nombre);
                        jugadores[p].numFichas = 0;
                        break;
                    }
                } while(hayPar || (jugadores[p].numFichas > 0 && accion != 2 && accion != 3));

                if(juegoTerminado) break; // Salir del for si alguien ganó
            }
        }

        // Verificar si todavía quedan pares posibles o fichas en banco
        int quedanPares = 0;
        for(int p = 0; p < numJugadores; p++) {
            if(jugadores[p].numFichas > 0) {
                if(descartarParejas(jugadores, p, nombreArchivo)) {
                    quedanPares = 1;
                    break;
                }
            }
        }

        // Condición de fin de juego: no hay pares y banco agotado
        if(!quedanPares && bancoIndice >= totalFichas) {
            printf("\nNo quedan pares posibles y se agotó el banco. Todos pierden.\n");
            juegoTerminado = 1;
        }
    }

    return bancoIndice;
}
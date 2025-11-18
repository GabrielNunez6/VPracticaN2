//
// Created by usuario on 11/17/2025.
//

#ifndef PROYECTOFINAL_TURNOS_H
#define PROYECTOFINAL_TURNOS_H
#include "jugador.h"
#include "domino.h"
#define MAX_JUGADORES 4

// La función devuelve el índice actualizado del banco
int jugarTurnos(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice, char nombreArchivo[]);
int puedeFormarPar(Jugador jugador);

#endif //PROYECTOFINAL_TURNOS_H
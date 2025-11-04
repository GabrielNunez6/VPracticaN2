//
// Created by usuario on 11/3/2025.
//
#include "menupoker.h"
#include "Poker3Card.h"

#ifndef P7_FUNCIONESDELPOKER_H
#define P7_FUNCIONESDELPOKER_H

int pedirNumeroJugadores();
void pedirNombreJugadores(Jugador jugadores[], int numJugadores);
int preguntarContinuar(char nombre[]);
void mostrarResultadosFinales(Jugador jugadores[], int numJugadores);
int contarJugadoresActivos(Jugador jugadores[], int numJugadores);
Jugador repartirCartas(Jugador jugadores[], int numJugadores, Carta mazo[]);
void mostrarCartas(char nombre[], Carta mano[]);
void mostrarNombreJugada(int valor);

#endif //P7_FUNCIONESDELPOKER_H
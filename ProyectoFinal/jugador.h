//
// Created by usuario on 11/17/2025.
//

#ifndef PROYECTOFINAL_JUGADOR_H
#define PROYECTOFINAL_JUGADOR_H
#define MAX_FICHAS_JUGADOR 28
#include "domino.h"

#include "domino.h"

#define MAX_FICHAS_JUGADOR 28

// Estructura para representar a un jugador
typedef struct {
    Domino mano[MAX_FICHAS_JUGADOR];
    int numFichas;
    int paresFormados; // contador de pares descartados
    char nombre[50];   // nombre del jugador
} Jugador;

// Funciones del módulo
void repartirFichas(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice);
void mostrarManos(Jugador jugadores[], int numJugadores);
int suma20(Domino a, Domino b);
int descartarParejas(Jugador jugadores[], int indiceJugador, char nombreArchivo[]);
void mostrarMano(Jugador jugador);


#endif //PROYECTOFINAL_JUGADOR_H
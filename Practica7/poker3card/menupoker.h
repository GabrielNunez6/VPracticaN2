#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Poker3Card.h"
#include "BarajaInglesa.h"

typedef struct {
    int id;
    char nombre[20];
    int saldo;
    int rondasJugadas;
    int activo;
    Carta cartas[3];
} Jugador;

int pedirNumeroJugadores();
void pedirNombreJugadores(Jugador jugadores[], int numJugadores);
int preguntarContinuar(char nombre[]);
void mostrarResultadosFinales(Jugador jugadores[], int numJugadores);
int contarJugadoresActivos(Jugador jugadores[], int numJugadores);
void jugarMano(Jugador jugadores[], int indiceJugador, Carta dealerCartas[]);
void mostrarCartas(char nombre[], Carta mano[]);
Jugador repartirCartas(Jugador jugadores[], int numJugadores, Carta mazo[]);


#endif
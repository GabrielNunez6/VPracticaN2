//
// Created by usuario on 11/17/2025.
//
// MenuLucky20.c
// Contiene las funciones del menú principal, configuración de modo prueba
// y la función que inicia una partida completa de Lucky 20.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"
#include "turnos.h"
#include "registroPartida.h"
#include "ganador.h"

// ------------------------
// Función: menuPrincipal
// Muestra el menú principal del juego y solicita una opción al usuario.
// Devuelve: la opción elegida por el usuario (1-4)
// ------------------------
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

// ------------------------
// Función: configurarModoPrueba
// Configura la partida para modo prueba. El jugador 0 recibe fichas que
// garantizan formar un par que sume 20 puntos.
// Parámetros:
//   jugadores[]: arreglo de jugadores
//   numJugadores: cantidad de jugadores
//   mazo[]: mazo de fichas
//   bancoIndice: índice actual del banco de fichas
// Devuelve: el índice actualizado del banco de fichas
// ------------------------
int configurarModoPrueba(Jugador jugadores[], int numJugadores, Domino mazo[], int bancoIndice) {
    // Jugador 0 recibe fichas que forman un par seguro
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

    return bancoIndice; // Devolver índice actualizado
}

// ------------------------
// Función: jugarPartida
// Ejecuta una partida completa de Lucky 20. Maneja el flujo general:
//   - Solicita número de jugadores y tipo de dominó
//   - Crea y mezcla el mazo
//   - Inicializa jugadores
//   - Reparte fichas (modo normal o prueba)
//   - Llama a la función jugarTurnos para iniciar la partida
// Parámetros:
//   modoPrueba: 0 para partida normal, 1 para modo prueba
// ------------------------
void jugarPartida(int modoPrueba) {
    int numJugadores, tipoDomino;

    // Solicitar configuración inicial al usuario
    printf("Numero de jugadores (1-4): ");
    scanf("%d", &numJugadores);
    printf("Tipo de domino (6,9,12): ");
    scanf("%d", &tipoDomino);

    // Crear el mazo según el tipo seleccionado
    Domino mazo[MAX_FICHAS];
    int totalFichas = crearMazo(mazo, tipoDomino);

    // Mezclar las fichas aleatoriamente
    mezclarMazo(mazo, totalFichas);

    // Inicializar los jugadores
    Jugador jugadores[MAX_JUGADORES];
    for(int i = 0; i < numJugadores; i++){
        jugadores[i].numFichas = 0;                       // Sin fichas al inicio
        sprintf(jugadores[i].nombre, "Jugador %d", i+1);  // Nombres por defecto
    }

    // Generar nombre de archivo para guardar la partida
    int bancoIndice = 0;
    char nombreArchivoPartida[100];
    generarNombreArchivo(nombreArchivoPartida);
    printf("Archivo de la partida: %s\n", nombreArchivoPartida);

    // Reparto de fichas
    if(modoPrueba){
        // Configuración especial para modo prueba
        bancoIndice = configurarModoPrueba(jugadores, numJugadores, mazo, bancoIndice);
    } else {
        // Reparto normal para todos los jugadores
        for(int i = 0; i < numJugadores; i++){
            while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas){
                jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
                jugadores[i].numFichas++;
                bancoIndice++;
            }
        }
    }

    // Iniciar los turnos de la partida
    bancoIndice = jugarTurnos(jugadores, numJugadores, mazo, totalFichas, bancoIndice, nombreArchivoPartida);
}

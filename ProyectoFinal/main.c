#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"
#include "turnos.h"
#include "registroPartida.h"
#include "ganador.h"

#define MAX_JUGADORES 4
#define MAX_FICHAS 91

int main(){
    initAleatorio();
    int opcionMenu=0;

    while(opcionMenu != 4){
        printf("\n=== LUCKY 20 ===\n");
        printf("1) Jugar nueva partida\n");
        printf("2) Consultar historial de ganadores\n");
        printf("3) Reproducir partida guardada\n");
        printf("4) Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d",&opcionMenu);

        if(opcionMenu == 1){
            int numJugadores, tipoDomino, modoPrueba;
            printf("Modo prueba? (0=no,1=si): ");
            scanf("%d",&modoPrueba);
            printf("Numero de jugadores (1-4): ");
            scanf("%d",&numJugadores);
            printf("Tipo de domino (6,9,12): ");
            scanf("%d",&tipoDomino);

            // Crear mazo
            Domino mazo[MAX_FICHAS];
            int totalFichas = crearMazo(mazo, tipoDomino);
            mezclarMazo(mazo, totalFichas);

            // Inicializar jugadores
            Jugador jugadores[MAX_JUGADORES];
            for(int i=0; i<numJugadores; i++){
                jugadores[i].numFichas = 0;
                sprintf(jugadores[i].nombre, "Jugador %d", i+1); // Nombres por defecto
            }

            int bancoIndice = 0;
            char nombreArchivoPartida[100];
            generarNombreArchivo(nombreArchivoPartida);
            printf("Archivo de la partida: %s\n", nombreArchivoPartida);

            // Reparto de fichas
            if(modoPrueba){
                // Jugador 0 recibe fichas que garantizan formar un par
                jugadores[0].mano[0] = (Domino){10,10};
                jugadores[0].mano[1] = (Domino){10,10};
                jugadores[0].numFichas = 2;

                // Reparto normal para los demás jugadores
                for(int i=1; i<numJugadores; i++){
                    while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas){
                        jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
                        jugadores[i].numFichas++;
                        bancoIndice++;
                    }
                }
            } else {
                // Reparto normal para todos
                for(int i=0; i<numJugadores; i++){
                    while(jugadores[i].numFichas < 6 && bancoIndice < totalFichas){
                        jugadores[i].mano[jugadores[i].numFichas] = mazo[bancoIndice];
                        jugadores[i].numFichas++;
                        bancoIndice++;
                    }
                }
            }

            // Inicia los turnos
            bancoIndice = jugarTurnos(jugadores, numJugadores, mazo, totalFichas, bancoIndice, nombreArchivoPartida);

        } else if(opcionMenu == 2){
            mostrarHistorial();
        } else if(opcionMenu == 3){
            char archivo[100];
            printf("Ingrese nombre de archivo de la partida: ");
            scanf("%s", archivo);
            reproducirPartida(archivo);
        } else if(opcionMenu == 4){
            printf("Gracias por jugar Lucky 20!\n");
        } else {
            printf("Opción inválida, intente de nuevo.\n");
        }
    }

    return 0;
}
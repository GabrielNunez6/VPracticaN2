//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include "turnos.h"
#include "jugador.h"
#include "domino.h"

int jugarTurnos(Jugador jugadores[], int numJugadores, Domino mazo[], int totalFichas, int bancoIndice){
    int jugadorActivo[MAX_JUGADORES];
    int i, j;
    for(i=0;i<numJugadores;i++) jugadorActivo[i]=1;

    int juegoTerminado=0;
    while(juegoTerminado==0){
        for(i=0;i<numJugadores;i++){
            if(jugadorActivo[i]==1){
                int accion=0;
                while(accion<1 || accion>3){
                    printf("\nTurno del jugador %d\n", i+1);
                    printf("Fichas en mano: ");
                    for(j=0;j<jugadores[i].numFichas;j++)
                        printf("[%d|%d] ", jugadores[i].mano[j].lado1,jugadores[i].mano[j].lado2);
                    printf("\nFichas en banco: %d\n", totalFichas - bancoIndice);
                    printf("Accion: 1) Formar par 2) Pedir 4 fichas 3) Retirarse: ");
                    scanf("%d",&accion);

                    if(accion==1)
                        descartarParejas(jugadores, numJugadores);

                    if(accion==2){
                        int fichasTomadas=0;
                        while(jugadores[i].numFichas<10 && bancoIndice<totalFichas && fichasTomadas<4){
                            jugadores[i].mano[jugadores[i].numFichas]=mazo[bancoIndice];
                            jugadores[i].numFichas++;
                            bancoIndice++;
                            fichasTomadas++;
                        }
                    }

                    if(accion==3){
                        jugadorActivo[i]=0;
                        printf("Jugador %d se retira.\n", i+1);
                    }
                }

                if(jugadores[i].numFichas==0){
                    printf("\n¡Jugador %d gana la partida!\n", i+1);
                    juegoTerminado=1;
                    break;
                }
            }
        }

        int todosRetirados=1;
        for(i=0;i<numJugadores;i++)
            if(jugadorActivo[i]==1) todosRetirados=0;
        if(todosRetirados==1) juegoTerminado=1;
    }

    return bancoIndice;
}
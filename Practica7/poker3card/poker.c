#include <stdio.h>
#include "MenuPoker.h"
#include "BarajaInglesa.h"
#include "Poker3Card.h"
#include "aleatorio.h"
#include "funcionesDelPoker.h"

#define MAX_JUGADORES 4
#define TAMANO_MANO 3
#define SALDO_INICIAL 300
#define VALOR_AS 14
#define MIN_APUESTA 10

int main() {
    initAleatorio();
    printf("=== THREE CARD POKER ===\n");

    int numJugadores = pedirNumeroJugadores();
    Jugador jugadores[MAX_JUGADORES];
    pedirNombreJugadores(jugadores,numJugadores);

    Carta mazo[52];
    int hayJugadoresActivos=1;

    while(hayJugadoresActivos){
        int activos = contarJugadoresActivos(jugadores,numJugadores);
        if(activos==0){
            printf("\nTodos los jugadores se han quedado sin dinero.\n");
            break;
        }

        printf("\n--- NUEVA RONDA ---\n");
        llenarYMezclarBaraja(mazo,52);
        Jugador dealer = repartirCartas(jugadores,numJugadores,mazo);

        for(int i=0;i<numJugadores;i++){
            if(jugadores[i].activo && jugadores[i].saldo>0)
                jugarMano(jugadores,i,dealer.cartas);
        }

        hayJugadoresActivos=0;
        for(int i=0;i<numJugadores;i++)
            if(jugadores[i].activo && jugadores[i].saldo>0)
                hayJugadoresActivos=1;
    }

    mostrarResultadosFinales(jugadores,numJugadores);
    printf("\nGracias por jugar Three Card Poker.\n");
    return 0;
}
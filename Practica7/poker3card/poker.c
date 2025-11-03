#include <stdio.h>
#include "BarajaInglesa.h"
#include "Poker3Card.h"
#include "menupoker.h"
#include "aleatorio.h"

#define TAMANO_MANO 3
#define APUESTA 50

int main() {
    initAleatorio();

    printf("=== POKER DE 3 CARTAS ===\n");

    // Pedir jugadores y nombres
    int numJugadores = pedirNumeroJugadores();
    Jugador jugadores[numJugadores];
    pedirNombreJugadores(jugadores, numJugadores);

    Carta mazo[52];
    int hayJugadoresActivos = 1;

    while (hayJugadoresActivos) {
        int activos = contarJugadoresActivos(jugadores, numJugadores);

        if (activos == 0) {
            printf("\nTodos los jugadores se han quedado sin dinero.\n");
            hayJugadoresActivos = 0;
        } else {
            printf("\n--- NUEVA RONDA ---\n");

            llenarYMezclarBaraja(mazo, 52);

            Jugador dealer = repartirCartas(jugadores, numJugadores, mazo);

            mostrarCartas(NULL, dealer.cartas);

            // Evaluar cada jugador
            for (int i = 0; i < numJugadores; i++) {
                if (jugadores[i].activo && jugadores[i].saldo > 0) {
                    mostrarCartas(jugadores[i].nombre, jugadores[i].cartas);
                    jugadores[i].rondasJugadas++;
                    jugarMano(jugadores, i, dealer.cartas);
                }
            }
        }
    }

    mostrarResultadosFinales(jugadores, numJugadores);
    printf("\nGracias por jugar Poker de 3 Cartas.\n");
    return 0;
}


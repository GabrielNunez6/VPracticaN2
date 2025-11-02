#include <stdio.h>
#include "BarajaInglesa.h"
#include "Poker3Card.h"

#define MAX_JUGADORES 4
#define TAMANO_MANO 3

int main() {
    initAleatorio();
    printf("=== POKER DE 3 CARTAS===\n");

    int numJugadores;
    do {
        printf("Cuantos jugadores participaran? (1-4): ");
        scanf("%d", &numJugadores);
        if (numJugadores < 1 || numJugadores > MAX_JUGADORES) {
            printf("Ingresa un valor entre 1 y 4.\n");
        }
    } while (numJugadores < 1 || numJugadores > MAX_JUGADORES);

    Jugador jugadores[MAX_JUGADORES];
    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].id = i + 1;
        jugadores[i].saldo = 50;
        jugadores[i].rondasJugadas = 0;
    }
    Jugador dealer;
    Carta mazo[52];
    char continuar = 's';


    while (continuar == 's') {
        printf("\n--- SIGUIENTE RONDA ---\n");
        llenarYMezclarBaraja(mazo, 52);

        int contador = 0;

        for (int i = 0; i < numJugadores; i++) {
            for (int j = 0; j < TAMANO_MANO; j++) {
                jugadores[i].cartas[j] = mazo[contador++];
            }
        }
        for (int j = 0; j < TAMANO_MANO; j++) {
            dealer.cartas[j] = mazo[contador++];
        }

        printf("\nEl dealer tiene: ");
        for (int j = 0; j < TAMANO_MANO; j++) {
            mostrarCarta(dealer.cartas[j]);
            printf("  ");
        }
        printf("\n");

        int apuesta = 50;
        for (int i = 0; i < numJugadores; i++) {
            printf("\nJugador %d recibe: ", jugadores[i].id);
            for (int j = 0; j < TAMANO_MANO; j++) {
                mostrarCarta(jugadores[i].cartas[j]);
                printf("  ");
            }

            jugadores[i].rondasJugadas++;

            int valorJugador = 0, valorDealer = 0;

            if (esStraightFlush(jugadores[i].cartas))
                valorJugador = 6;
            else if (esThreeOfAKind(jugadores[i].cartas))
                valorJugador = 5;
            else if (esStraight(jugadores[i].cartas))
                valorJugador = 4;
            else if (esFlush(jugadores[i].cartas))
                valorJugador = 3;
            else if (esOnePair(jugadores[i].cartas))
                valorJugador = 2;
            else valorJugador = 1;

            if (esStraightFlush(dealer.cartas))
                valorDealer = 6;
            else if (esThreeOfAKind(dealer.cartas))
                valorDealer = 5;
            else if (esStraight(dealer.cartas))
                valorDealer = 4;
            else if (esFlush(dealer.cartas))
                valorDealer = 3;
            else if (esOnePair(dealer.cartas))
                valorDealer = 2;
            else valorDealer = 1;

            if (valorJugador > valorDealer) {
                printf("\nugador %d gana contra el dealer.", jugadores[i].id);
                jugadores[i].saldo += apuesta;
            } else if (valorJugador < valorDealer) {
                printf("\nJugador %d pierde contra el dealer.", jugadores[i].id);
                jugadores[i].saldo -= apuesta;
            } else {

                Carta altaJ = esHighCard(jugadores[i].cartas);
                Carta altaD = esHighCard(dealer.cartas);

                if (altaJ.valor > altaD.valor) {
                    printf("\nJugador %d gana por carta alta.", jugadores[i].id);
                    jugadores[i].saldo += apuesta;
                } else if (altaJ.valor < altaD.valor) {
                    printf("\nJugador %d pierde por carta alta.", jugadores[i].id);
                    jugadores[i].saldo -= apuesta;
                } else {
                    printf("\nJugador %d empata con el dealer.", jugadores[i].id);
                }
            }
            printf("\nSaldo actual: $%d\n", jugadores[i].saldo);


            if (jugadores[i].saldo <= 0) {
                printf("Jugador %d ya no tiene dinero para apostar y se retira.\n", jugadores[i].id);
                jugadores[i].saldo = 0;
            }
        }

        printf("\nQuieren jugar otra ronda? (s/n): ");
        scanf(" %c", &continuar);
    }
}

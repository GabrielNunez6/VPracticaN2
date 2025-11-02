#include <stdio.h>
#include "BarajaInglesa.h"
#include "Poker3Card.h"
#include "aleatorio.h"

#define MAX_JUGADORES 4
#define TAMANO_MANO 3

int main() {
    initAleatorio();
    printf("=== POKER DE 3 CARTAS ===\n");

    int numJugadores;
    // Solicita el número de jugadores
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
        jugadores[i].saldo = 300;
        jugadores[i].rondasJugadas = 0;
        jugadores[i].activo = 1;

        printf("Ingresa el nombre del jugador %d: ", i + 1);
        scanf("%s", jugadores[i].nombre);
    }

    Jugador dealer;
    Carta mazo[52];
    int hayJugadoresActivos = 1;

    while (hayJugadoresActivos) {
        int jugadoresActivos = 0;
        for (int i = 0; i < numJugadores; i++) {
            if (jugadores[i].activo && jugadores[i].saldo > 0)
                jugadoresActivos++;
        }

        if (jugadoresActivos == 0) {
            printf("\nTodos los jugadores se han quedado sin dinero.\n");
            hayJugadoresActivos = 0;
        }
        else {
            printf("\n--- NUEVA RONDA ---\n");
            llenarYMezclarBaraja(mazo, 52);

            int contador = 0;

            // Repartir cartas a jugadores activos
            for (int i = 0; i < numJugadores; i++) {
                if (jugadores[i].activo && jugadores[i].saldo > 0) {
                    for (int j = 0; j < TAMANO_MANO; j++) {
                        jugadores[i].cartas[j] = mazo[contador++];
                    }
                }
            }

            // Repartir cartas al dealer
            for (int j = 0; j < TAMANO_MANO; j++) {
                dealer.cartas[j] = mazo[contador++];
            }

            // Mostrar cartas del dealer
            printf("\nDealer tiene: ");
            for (int j = 0; j < TAMANO_MANO; j++) {
                mostrarCarta(dealer.cartas[j]);
                printf("  ");
            }

            int apuesta = 50;
            int valorDealer = 0;

            // Evaluar la mano del dealer
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
            else
                valorDealer = 1;

            // Mostrar categoría de la mano del dealer
            printf("\nDealer tiene ");
            if (valorDealer == 6)
                printf("Straight Flush\n");
            else if (valorDealer == 5)
                printf("Three of a Kind\n");
            else if (valorDealer == 4)
                printf("Straight\n");
            else if (valorDealer == 3)
                printf("Flush\n");
            else if (valorDealer == 2)
                printf("Un par\n");
            else
                printf("Carta alta\n");

            // Evaluar cada jugador
            for (int i = 0; i < numJugadores; i++) {
                if (!jugadores[i].activo || jugadores[i].saldo <= 0)
                    continue;

                printf("\n%s recibe: ", jugadores[i].nombre);
                for (int j = 0; j < TAMANO_MANO; j++) {
                    mostrarCarta(jugadores[i].cartas[j]);
                    printf("  ");
                }

                jugadores[i].rondasJugadas++;

                int valorJugador = 0;
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
                else
                    valorJugador = 1;

                printf("\n%s tiene ", jugadores[i].nombre);
                if (valorJugador == 6)
                    printf("Straight Flush");
                else if (valorJugador == 5)
                    printf("Three of a Kind");
                else if (valorJugador == 4)
                    printf("Straight");
                else if (valorJugador == 3)
                    printf("Flush");
                else if (valorJugador == 2)
                    printf("Un par");
                else
                    printf("Carta alta");

                if (valorJugador > valorDealer) {
                    printf("\n%s gana contra el dealer.", jugadores[i].nombre);
                    jugadores[i].saldo += apuesta;
                } else if (valorJugador < valorDealer) {
                    printf("\n%s pierde contra el dealer.", jugadores[i].nombre);
                    jugadores[i].saldo -= apuesta;
                } else {
                    // Empate por tipo de mano: desempate por carta alta
                    Carta altaJ = esHighCard(jugadores[i].cartas);
                    Carta altaD = esHighCard(dealer.cartas);

                    if (altaJ.valor > altaD.valor) {
                        printf("\n%s gana por carta alta.", jugadores[i].nombre);
                        jugadores[i].saldo += apuesta;
                    } else if (altaJ.valor < altaD.valor) {
                        printf("\n%s pierde por carta alta.", jugadores[i].nombre);
                        jugadores[i].saldo -= apuesta;
                    } else {
                        printf("\n%s empata con el dealer.", jugadores[i].nombre);
                    }
                }

                printf("\nSaldo actual: $%d\n", jugadores[i].saldo);

                if (jugadores[i].saldo <= 0) {
                    printf("%s ya no tiene dinero y se retira.\n", jugadores[i].nombre);
                    jugadores[i].activo = 0;
                } else {

                    char continuar;
                    printf("%s desea seguir jugando? (s/n): ", jugadores[i].nombre);
                    scanf(" %c", &continuar);
                    if (continuar != 's') {
                        jugadores[i].activo = 0;
                        printf("%s se retira del juego.\n", jugadores[i].nombre);
                    }
                }
            }
        }
    }

    printf("\n=== RESULTADOS FINALES ===\n");
    int mayorSaldo = jugadores[0].saldo;
    for (int i = 1; i < numJugadores; i++) {
        if (jugadores[i].saldo > mayorSaldo) mayorSaldo = jugadores[i].saldo;
    }

    for (int i = 0; i < numJugadores; i++) {
        printf("%s -> Saldo: $%d | Rondas Jugadas: %d", jugadores[i].nombre, jugadores[i].saldo, jugadores[i].rondasJugadas);
        if (jugadores[i].saldo == mayorSaldo)
            printf("  GANADOR");
        printf("\n");
    }

    printf("\nGracias por jugar Poker de 3 Cartas.\n");
    return 0;
}

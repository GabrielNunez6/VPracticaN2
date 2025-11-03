#include <stdio.h>
#include "MenuPoker.h"

#define APUESTA 50
#define TAMANO_MANO 3

/**
 * Solicita al usuario el número de jugadores (1-4)
 * @return Número de jugadores ingresado por el usuario
 */
int pedirNumeroJugadores() {
    int numJugadores;
    do {
        printf("Cuantos jugadores participaran? (1-4): ");
        scanf("%d", &numJugadores);
        if (numJugadores < 1 || numJugadores > 4)
            printf("Ingresa un valor entre 1 y 4.\n");
    } while (numJugadores < 1 || numJugadores > 4);
    return numJugadores;
}

/**
 * Solicita los nombres de los jugadores y los inicializa
 * @param jugadores Arreglo de jugadores a inicializar
 * @param numJugadores Cantidad de jugadores
 */
void pedirNombreJugadores(Jugador jugadores[], int numJugadores) {
    for (int i = 0; i < numJugadores; i++) {
        jugadores[i].id = i + 1;
        jugadores[i].saldo = 300;
        jugadores[i].rondasJugadas = 0;
        jugadores[i].activo = 1;

        printf("Ingresa el nombre del jugador %d: ", i + 1);
        scanf("%s", jugadores[i].nombre);
    }
}

/**
 * Pregunta a un jugador si desea continuar jugando
 * @param nombre Nombre del jugador
 * @return 1 si desea continuar, 0 si desea retirarse
 */
int preguntarContinuar(char nombre[]) {
    char respuesta;
    printf("%s desea seguir jugando? (s/n): ", nombre);
    scanf(" %c", &respuesta);
    if (respuesta == 's' || respuesta == 'S')
        return 1;
    else
        return 0;
}

/**
 * Muestra los resultados finales del juego
 * @param jugadores vector de jugadores
 * @param numJugadores Cantidad de jugadores
 */
void mostrarResultadosFinales(Jugador jugadores[], int numJugadores) {
    int mayorSaldo = jugadores[0].saldo;
    int hayGanador = 0;

    for (int i = 1; i < numJugadores; i++)
        if (jugadores[i].saldo > mayorSaldo)
            mayorSaldo = jugadores[i].saldo;

    printf("\n=== RESULTADOS FINALES ===\n");
    for (int i = 0; i < numJugadores; i++) {
        printf("%s -> Saldo: $%d | Rondas: %d", jugadores[i].nombre, jugadores[i].saldo, jugadores[i].rondasJugadas);

        // Solo marcar ganador si tiene saldo positivo y es el mayor
        if (jugadores[i].saldo == mayorSaldo && mayorSaldo > 0) {
            printf("  GANADOR");
            hayGanador = 1;
        }

        printf("\n");
    }

    if (!hayGanador) {
        printf("Ningun jugador tiene saldo positivo. Todos perdieron.\n");
    }
}

int contarJugadoresActivos(Jugador jugadores[], int numJugadores) {
    int activos = 0;
    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].activo && jugadores[i].saldo > 0) {
            activos++;
        }
    }
    return activos;
}

/**
* Reparte cartas a los jugadores activos y al dealer.
*
* @param jugadores Vector de jugadores.
* @param numJugadores Cantidad de jugadores.
* @param dealer Jugador que representa al dealer.
* @param mazo Arreglo de cartas de la baraja.
*/
Jugador repartirCartas(Jugador jugadores[], int numJugadores, Carta mazo[]) {
    Jugador dealer;
    int contador = 0;

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
    return dealer;
}

/**
* Muestra las cartas de un jugador o del dealer.
*
* @param nombre Nombre del jugador, o NULL si es el dealer.
* @param mano Vector de cartas de la mano.
*/
void mostrarCartas(char nombre[], Carta mano[]) {
    if (nombre != NULL) {
        printf("\n%s tiene: ", nombre);
    } else {
        printf("\nDealer tiene: ");
    }
    for (int i = 0; i < TAMANO_MANO; i++) {
        mostrarCarta(mano[i]);
        printf("  ");
    }
}

/**
* Esta funcion evalúa el resultado de la mano de un jugador contra el dealer,
* actualiza el saldo y pregunta si desea continuar jugando.

* @param jugadores Vector de jugadores.
* @param indiceJugador Índice del jugador dentro del vector.
* @param dealerCartas Vector de cartas del dealer.
*/
void jugarMano(Jugador jugadores[], int indiceJugador, Carta dealerCartas[]) {
    int valorJugador = valorMano(jugadores[indiceJugador].cartas);
    int valorDealer = valorMano(dealerCartas);

    if (valorJugador > valorDealer) {
        printf("\n %s gana contra el dealer.\n", jugadores[indiceJugador].nombre);
        jugadores[indiceJugador].saldo += APUESTA;
    } else if (valorJugador < valorDealer) {
        printf("\n %s pierde contra el dealer.\n", jugadores[indiceJugador].nombre);
        jugadores[indiceJugador].saldo -= APUESTA;
    } else {

        //EN CASO DE EMPATE , HACEN UN DESEMPATE POR CARTA MAS ALTA
        Carta altaJ = esHighCard(jugadores[indiceJugador].cartas);
        Carta altaD = esHighCard(dealerCartas);

        if (altaJ.valor > altaD.valor) {
            printf("\n%s gana por carta alta.\n", jugadores[indiceJugador].nombre);
            jugadores[indiceJugador].saldo += APUESTA;
        } else if (altaJ.valor < altaD.valor) {
            printf("\n%s pierde por carta alta.\n", jugadores[indiceJugador].nombre);
            jugadores[indiceJugador].saldo -= APUESTA;
        } else {
            printf("\n%s empata con el dealer.\n", jugadores[indiceJugador].nombre);
        }
    }

    printf("Saldo actual: $%d\n", jugadores[indiceJugador].saldo);

    if (jugadores[indiceJugador].saldo <= 0) {
        printf("%s ya no tiene dinero y se retira.\n", jugadores[indiceJugador].nombre);
        jugadores[indiceJugador].activo = 0;
    } else {
        int sigue = preguntarContinuar(jugadores[indiceJugador].nombre);
        if (!sigue) {
            jugadores[indiceJugador].activo = 0;
            printf("%s se retira del juego.\n", jugadores[indiceJugador].nombre);
        }
    }
}

#include <stdio.h>
#include "aleatorio.h"
#include "combinaciones.h"
#include "menu.h"

int main() {
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
    int opcion;

    do {
        MenuCombinaciones();
        opcion = OpcionNumero(1, 7);

        switch (opcion) {
            case 1: // Lanzar los 5 dados
                d1 = 2;
                d2 = 3;
                d3 = 4;
                d4 = 5;
                d5 = 6;
                printf("Dados lanzados.\n");
                break;

            case 2: // Mostrar los 5 dados
                printf("Los dados lanzados fueron: %d %d %d %d %d\n", d1, d2, d3, d4, d5);
                break;

            case 3: // Balut
                if (sumaSiIguales(d1, d2, d3, d4, d5)) {
                    printf("\nBalut!  Puntos: 30\n");
                } else {
                    printf("No hay Balut.\n");
                }
                break;

            case 4: { // Full House
                if (sumaSiHayFullHouse(d1, d2, d3, d4, d5)) {
                    printf("Full House!  Puntos: 28\n");
                } else {
                    printf("No hay Full House.\n");
                }
                break;
            }

            case 5: // Secuencia baja (1 al 5)
                if (esSecuenciaBaja(d1, d2, d3, d4, d5)) {
                    printf("Hay una secuencia baja (1 al 5) - Puntos: 15\n");
                } else {
                    printf("No hay secuencia baja.\n");
                }
                break;
            case 6: // Secuencia alta (2 al 6)
                if (esSecuenciaAlta(d1, d2, d3, d4, d5)) {
                    printf("Hay una secuencia alta (2 al 6) - Puntos: 20\n");
                } else {
                    printf("No hay secuencia alta.\n");
                }
                break;

            case 7: // Terminar el programa
                printf("Terminar.\n");
                break;

        }

    } while (opcion != 7);

    return 0;
}

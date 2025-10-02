#include <stdio.h>
#include "aleatorio.h"
#include "combinaciones.h"
#include "menu.h"

int main() {
    int d1=0, d2=0, d3=0, d4=0, d5=0;
    int opcion;

    do {
        MenuCombinaciones();
        opcion = OpcionNumero(1,7);

        switch(opcion) {
            case 1: // Lanzar los 5 dados
                d1 = 1;
                d2 = 1;
                d3 = 1;
                d4 = 2;
                d5 = 2;
                printf("Dados lanzados.\n");
                break;

            case 2: // Mostrar los 5 dados
                printf("Los dados lanzados fueron: %d %d %d %d %d\n", d1, d2, d3, d4, d5);
                break;

            case 3: // Balut
                if (sumaSiIguales(d1, d2, d3, d4, d5)) {
                    printf("\nBalut! La suma fue %d, Puntos:30\n", sumaSiIguales(d1,d2, d3, d4, d5));
                } else {
                    printf("No hay Balut.\n");
                }
                break;

            case 4: // Secuencia
                if (sumaSiEsSecuencia(d1, d2, d3, d4, d5)) {
                    printf("Los dados forman una secuencia. La suma es %d\n",
                           sumaSiEsSecuencia(d1,d2,d3,d4,d5));
                } else {
                    printf("No forman secuencia.\n");
                }
                break;
            case 5: { // Full House
                int full = sumaSiFullHouse(d1,d2,d3,d4,d5);
                if (full) {
                    printf("Full House! Suma: %d. Puntos: 28\n", full);
                } else {
                    printf("No hay Full House.\n");
                }
                break;
            }

            case 7: // Termina el programa
                printf("Terminar\n");
                break;
        }
    } while(opcion != 7);
    return 0;
}


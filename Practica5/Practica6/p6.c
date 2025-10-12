#include <stdio.h>
#include "aleatorio.h"
#include "combinacionesVectores.h"
#include "menu.h"
#include "combinaciones.h"


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
                int dados[] = {d1, d2, d3, d4, d5};
                int puntos = sumaSiIgualesVectores(dados, 5);

                if (puntos > 0) {
                    printf("\n¡Balut! Puntos: 30\n");
                } else {
                    printf("No hay Balut.\n");
                }
                break;


        }


    } while(opcion != 7);
    return 0;
}

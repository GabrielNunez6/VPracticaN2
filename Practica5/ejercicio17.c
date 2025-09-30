#include <stdio.h>
#include "aleatorio.h"
#include "combinaciones.h"
#include "menu.h"


int main() {
    initAleatorio();
    int d1=0, d2=0, d3=0, d4=0, d5=0;
    int opcion;

    do {
        MenuCombinaciones();
        opcion=OpcionNumero(1,7);

        switch(opcion) {
            case 1: //Lanzar los 5 dados
                d1 = lanzarDado();
                d2 = lanzarDado();
                d3 = lanzarDado();
                d4 = lanzarDado();
                d5 = lanzarDado();
                printf("Dados lanzados.\n");
                break;
            case 2: //Muestra los 5 dados lanzados
                printf("Los dados lanzados fueron: %d %d %d %d %d\n", d1, d2, d3, d4, d5);
                break;
            case 3:
                if (sumaSiIguales(d1, d2, d3, d4, d5)) {
                   return d1 + d2 + d3 + d4 + d5;
                } else {
                    return 0;
                }
                break;
            case 7: //Termina el programa
                printf("Terminar");
                break;
        }
    } while(opcion != 7);
    return 0;
}

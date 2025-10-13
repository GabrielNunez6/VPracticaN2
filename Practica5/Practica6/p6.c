#include <stdio.h>
#include "aleatorio.h"
#include "combinacionesVectores.h"
#include "menu.h"
#include "combinaciones.h"

int main() {
    int dados[5] = {0};
    int opcion;

    do {
        MenuCombinaciones();
        opcion = OpcionNumero(1,7);

        switch(opcion) {
            case 1: // Lanzar dados
                dados[0] = 2;
                dados[1] = 3;
                dados[2] = 4;
                dados[3] = 5;
                dados[4] = 6;
                printf("Dados lanzados.\n");
                break;

            case 2: // Mostrar dados
                printf("Los dados lanzados fueron: ");
                for(int i = 0; i < 5; i++)
                    printf("%d ", dados[i]);
                printf("\n");
                break;

            case 3: // Balut
            {
                int puntos = sumaSiIgualesVectores(dados, 5);
                if(puntos > 0)
                    printf("¡Balut! Puntos: 30\n");
                else
                    printf("No hay Balut.\n");
                break;
            }

            case 4: // Full House
            {
                int puntos = fullHouse(dados, 5);
                if(puntos > 0)
                    printf("¡Full House! Puntos: 28\n");
                else
                    printf("No es Full House.\n");
                break;
            }

            case 5: // Secuencia baja (1-5)
            {
                int puntos = esSecuenciaBajaVectores(dados, 5);
                if(puntos > 0)
                    printf("Secuencia baja (1-5)! Puntos: 15\n");
                else
                    printf("No es secuencia baja.\n");
                break;
            }

            case 6: // Secuencia alta (2-6)
            {
                int puntos = esSecuenciaAltaVectores(dados, 5);
                if(puntos > 0)
                    printf("Secuencia alta (2-6)! Puntos: 20\n");
                else
                    printf("No es secuencia alta.\n");
                break;
            }

            case 7: // Terminar
                printf("Programa terminado.\n");
                break;
        }

    } while(opcion != 7);

    return 0;
}


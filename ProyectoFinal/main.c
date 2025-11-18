#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorio.h"
#include "domino.h"
#include "jugador.h"
#include "turnos.h"
#include "registroPartida.h"
#include "ganador.h"
#include "MenuLucky20.h"

#define MAX_JUGADORES 4
#define MAX_FICHAS 91

int main() {
    initAleatorio();
    int opcion = 0;

    while(opcion != 4) {
        opcion = menuPrincipal();

        switch(opcion) {
            case 1: {
                int modoPrueba;
                printf("Modo prueba? (0=no,1=si): ");
                scanf("%d", &modoPrueba);
                jugarPartida(modoPrueba);
                break;
            }
            case 2:
                mostrarHistorial();
                break;
            case 3: {
                char archivo[100];
                printf("Ingrese nombre de archivo de la partida: ");
                scanf("%s", archivo);
                reproducirPartida(archivo);
                break;
            }
            case 4:
                printf("Gracias por jugar Lucky 20!\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    }
    return 0;
}

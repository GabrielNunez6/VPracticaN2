#include <stdio.h>
#include "aleatorio.h"
#include "menu.h"

int main() {
    char opcion;
    int tamano;
    int alto, largo;

    do {
        mostrarMenu();
        opcion = OpcionLetra('a', 'g');


        switch(opcion) {
            case 'a': // Rectángulo pide alto y largo
                printf("Introduce la altura: ");
                scanf("%d", &alto);
                printf("Introduce el largo: ");
                scanf("%d", &largo);
                figura1(alto, largo);
                break;
            case 'b':
                printf("Introduce el tamaño del triángulo: ");
                scanf("%d", &tamano);
                figura2(tamano);
                break;
            case 'c':
                printf("Introduce el tamaño del triángulo: ");
                scanf("%d", &tamano);
                figura3(tamano);
                break;
            case 'd':
                printf("Introduce el tamano del triangulo: ");
                scanf("%d", &tamano);
                figura4(tamano);
            case 'g':
                printf("Salir\n");
                break;
        }

    } while(opcion != 'g');

    return 0;
}
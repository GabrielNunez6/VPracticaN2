#include <stdio.h>
#include "aleatorio.h"
#include "menu.h"

int main() {
    char opcion;
    int n;
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

            case 'g':
                printf("Salir\n");
                break;
        }

    } while(opcion != 'g');

    return 0;
}
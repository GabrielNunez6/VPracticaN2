#include <stdio.h>
#include <string.h>
#include "cadenas.h"
#include "otrasFunciones.h"

void mostrarMenu() {
    printf("\n=== MENU DE OPERACIONES ===\n");
    printf("1. Buscar palabra en texto\n");
    printf("2. Sustituir palabra por su inversa en mayusculas\n");
    printf("3. Resaltar palabra con simbolo\n");
    printf("4. Listar frecuencia de palabras\n");
    printf("5. Borrar palabra\n");
    printf("0. Salir\n");
}

void ejecutarMenu() {
    char texto[1000] = "La casa de mi padre es la casa de mi madre y tambien es mi casa";
    char palabra[100];
    int posiciones[50];
    int opcion;

    do {
        mostrarMenu();
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                buscarPalabraEnTexto(texto);
                break;
            }
            case 2:
                sustituirPalabraInvertida(texto);
                break;


            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadenas.h"

void opcionContarPalabras() {
    char nombre[100];
    char linea[500];
    int total = 0;

    printf("\nIngresa el nombre del archivo: ");
    scanf("%s", nombre);

    FILE *archivo = fopen(nombre, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        total += contarPalabras(linea);
    }

    fclose(archivo);

    printf("\nEl archivo contiene %d palabras.\n", total);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "cadenas.h"

#define MAX_LINEA 1000
#define MAX_PALABRAS 5000
#define MAX_LONG_PALABRA 100
#define MAX_ARCHIVO 200


int main() {
    char nombreArchivo[MAX_ARCHIVO];
    int opcion;

    // Pedir archivo inicial
    do {
        printf("Ingrese el nombre del archivo: ");
        fgets(nombreArchivo, MAX_ARCHIVO, stdin);
        limpiar_salto(nombreArchivo);
        FILE *archivo = fopen(nombreArchivo, "r");
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo '%s'. Intente nuevamente.\n", nombreArchivo);
        } else {
            fclose(archivo);
        }
    } while (strlen(nombreArchivo) == 0 || fopen(nombreArchivo, "r") == NULL);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Contar palabras\n");
        printf("2. Mostrar palabras unicas\n");
        printf("3. Buscar palabra\n");
        printf("4. Cambiar archivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: {
                char linea[MAX_LINEA];
                int total = 0;
                FILE *archivo = fopen(nombreArchivo, "r");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo '%s'\n", nombreArchivo);
                    break;
                }
                while (fgets(linea, MAX_LINEA, archivo) != NULL) {
                    total += contarPalabras(linea);
                }
                fclose(archivo);
                printf("Cantidad de palabras: %d\n", total);
                break;
            }
            case 2:
                mostrar_unicas(nombreArchivo);
                break;
            case 3: {
                char palabra[MAX_LONG_PALABRA];
                printf("Ingrese palabra a buscar: ");
                fgets(palabra, MAX_LONG_PALABRA, stdin);
                limpiar_salto(palabra);
                a_minusculas(palabra);
                buscar_palabra(nombreArchivo, palabra);
                break;
            }case 4: {
                int archivoValido = 0;
                do {
                    printf("Ingrese nuevo archivo: ");
                    fgets(nombreArchivo, MAX_ARCHIVO, stdin);
                    limpiar_salto(nombreArchivo);

                    FILE *archivo = fopen(nombreArchivo, "r");
                    if (archivo == NULL) {
                        printf("No se pudo abrir el archivo '%s'. Intente nuevamente.\n", nombreArchivo);
                    } else {
                        fclose(archivo);
                        archivoValido = 1;
                    }
                } while (!archivoValido);
                break;
            }
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}
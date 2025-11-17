#include <stdio.h>
#include "menu.h"
#include <string.h>
#include <ctype.h>
#include "cadenas.h"

#define MAX_LINEA 200
#define MAX_PALABRAS 1000
#define MAX_LONG_PALABRA 50
#define MAX_ARCHIVO 100

/* Elimina el salto de línea '\n' al final de una cadena, si existe.
 *
 * Recorre la cadena hasta encontrar el carácter nulo '\0' y reemplaza
 * el primer '\n' por '\0', dejando la cadena lista para procesarse.
 *
 * @param str Cadena de caracteres que puede contener un salto de línea.
 */
void limpiar_salto(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] == '\n') {
            cadena[i] = '\0';
            break;
        }
        i++;
    }
}

/* Convierte todos los caracteres de una cadena a minúsculas.
 *
 * Recorre cada carácter de la cadena y, si es una letra mayúscula,
 * la convierte a minúscula usando su valor ASCII.
 *
 * @param str Cadena de caracteres que se desea convertir.
 */
void a_minusculas(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = cadena[i] + 32;
        }
        i++;
    }
}

/* Muestra todas las palabras únicas de un archivo dado por su nombre.
 *
 * La función abre el archivo, lee línea por línea, identifica palabras
 * y las muestra sin repetirlas.
 *
 * @param nombreArchivo Nombre del archivo que se desea analizar.
 */
void mostrar_unicas(char nombreArchivo[]) {
    FILE *archivo = fopen(nombreArchivo, "r"); // abrir archivo dentro de la función
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo '%s'\n", nombreArchivo);
        return;
    }

    char linea[200];
    char palabras[1000][50];
    int cont = 0;

    while (fgets(linea, 200, archivo) != NULL) {
        int i = 0, j = 0;
        char palabra[50];

        while (linea[i] != '\0') {
            if ((linea[i] >= 'A' && linea[i] <= 'Z') || (linea[i] >= 'a' && linea[i] <= 'z')) {
                palabra[j++] = tolower(linea[i]);
            } else if (j > 0) {
                palabra[j] = '\0';
                int existe = 0;
                for (int k = 0; k < cont; k++) {
                    if (strcmp(palabras[k], palabra) == 0) {
                        existe = 1;
                        break;
                    }
                }
                if (!existe && cont < 1000) {
                    strcpy(palabras[cont++], palabra);
                }
                j = 0;
            }
            i++;
        }

        if (j > 0) {
            palabra[j] = '\0';
            int existe = 0;
            for (int k = 0; k < cont; k++) {
                if (strcmp(palabras[k], palabra) == 0) {
                    existe = 1;
                    break;
                }
            }
            if (!existe && cont < 1000) {
                strcpy(palabras[cont++], palabra);
            }
        }
    }

    fclose(archivo);

    printf("Palabras unicas:\n");
    for (int i = 0; i < cont; i++) {
        printf("%s\n", palabras[i]);
    }
}
/* Busca una palabra dentro de un archivo dado por su nombre
 * usando la función buscarUbicaciones.
 *
 * @param nombreArchivo Nombre del archivo donde se realizará la búsqueda.
 * @param buscada       Palabra que se desea buscar en el archivo.
 */
void buscar_palabra(char nombreArchivo[], char buscada[]) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo '%s'\n", nombreArchivo);
        return;
    }

    char linea[200];
    int num_linea = 0;
    int encontrada = 0;

    while (fgets(linea, 200, archivo) != NULL) {
        num_linea++;
        int posiciones[200];
        int n = buscarUbicaciones(buscada, linea, posiciones); // usamos tu función
        if (n > 0) {
            printf("'%s' encontrada en linea %d\n", buscada, num_linea);
            encontrada = 1;
        }
    }

    if (!encontrada) {
        printf("'%s' no encontrada en el archivo.\n", buscada);
    }

    fclose(archivo);
}
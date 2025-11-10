#include <ctype.h>
#include <string.h>

void invertirCadena(char primeraCadena[], char cadenaResultado[]) {
    int longitud = strlen(primeraCadena);

    for (int i = 0; i < longitud; i++) {
        cadenaResultado[i] = primeraCadena[longitud - 1 - i];
    }
    cadenaResultado[longitud] = '\0';
}

int contarPalabras(char cadena[]) {
    int i = 0, palabra = 0, contador = 0;

    while (cadena[i] != '\0') {
        if (isalpha(cadena[i])) {
            if (!palabra) {
                palabra = 1;
                contador++;
            }
        } else {
            palabra = 0;
        }
        i++;
    }
    return contador;
}

int buscarUbicaciones(char palabra[], char texto[], int posiciones[]) {
    int lenPalabra = strlen(palabra);
    int n = 0;
    int i = 0;

    while (texto[i] != '\0') {
        if (strncasecmp(&texto[i], palabra, lenPalabra) == 0 &&
            (i == 0 || !isalpha(texto[i - 1])) &&
            !isalpha(texto[i + lenPalabra])) {
            posiciones[n++] = i;
            i += lenPalabra;
            } else {
                i++;
            }
    }
    return n;
}
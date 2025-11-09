#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "cadenas.h"

void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);

    }
}

void buscarPalabraEnTexto(char texto[]) {
    char palabra[100];
    int posiciones[50];

    printf("Palabra a buscar: ");
    scanf("%s", palabra);

    char textoCopia[1000];
    strcpy(textoCopia, texto);

    convertirMinusculas(palabra);
    convertirMinusculas(textoCopia);

    int n = buscarUbicaciones(palabra, textoCopia, posiciones);

    printf("\n'%s' aparece %d veces y tiene %d letras.\n",
           palabra, n, (int)strlen(palabra));
}


void sustituirPalabraInvertida(char texto[]) {
    char palabra[100];
    char invertida[100];
    printf("Palabra a sustituir: ");
    scanf("%s", palabra);

    int len = strlen(palabra);
    for (int i = 0; i < len; i++) {
        invertida[i] = toupper(palabra[len - 1 - i]);
    }
    invertida[len] = '\0';

    char resultado[1000] = "";
    int i = 0;

    while (texto[i] != '\0') {

        if (strncasecmp(&texto[i], palabra, len) == 0 &&
            (i == 0 || !isalpha(texto[i - 1])) &&
            !isalpha(texto[i + len])) {

            strcat(resultado, invertida);
            i += len;
            } else {

                int largo = strlen(resultado);
                resultado[largo] = texto[i];
                resultado[largo + 1] = '\0';
                i++;
            }
    }

    strcpy(texto, resultado);
    printf("\nTexto modificado:\n%s\n", texto);
}

void resaltarPalabraConSimbolo(char texto[]) {
    char palabra[100];
    char simbolo;
    printf("Palabra a resaltar: ");
    scanf("%s", palabra);
    printf("Símbolo: ");
    scanf(" %c", &simbolo);

    char resultado[2000] = "";
    int longitudPalabra = strlen(palabra);
    int i = 0;

    while (texto[i] != '\0') {
        int coincide = 1;

        // Verifica si las letras coinciden
        for (int j = 0; j < longitudPalabra; j++) {
            if (tolower(texto[i + j]) != tolower(palabra[j])) {
                coincide = 0;
                break;
            }
        }

        // Si la palabra coincide y está separada por espacios o signos
        if (coincide && (i == 0 || !isalpha(texto[i - 1])) &&
            !isalpha(texto[i + longitudPalabra])) {

            int len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            strcat(resultado, palabra);

            len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            i = i + longitudPalabra; // avanzar después de la palabra
            } else {
                int len = strlen(resultado);
                resultado[len] = texto[i];
                resultado[len + 1] = '\0';
                i++;
            }
    }

    printf("\nTexto resaltado:\n%s\n", resultado);
}
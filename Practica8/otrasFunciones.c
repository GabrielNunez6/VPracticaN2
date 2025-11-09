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
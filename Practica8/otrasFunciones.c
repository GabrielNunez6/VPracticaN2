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
    int posiciones[200];

    printf("Palabra a buscar: ");
    scanf("%99s", palabra);  // previene overflow

    char textoCopia[5000];
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
    scanf("%99s", palabra);

    int len = strlen(palabra);
    for (int i = 0; i < len; i++) {
        invertida[i] = toupper(palabra[len - 1 - i]);
    }
    invertida[len] = '\0';

    char resultado[5000] = "";
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
    scanf("%99s", palabra);
    printf("Símbolo: ");
    scanf(" %c", &simbolo);

    char resultado[5000] = "";
    int longitudPalabra = strlen(palabra);
    int i = 0;

    while (texto[i] != '\0') {
        int coincide = 1;

        for (int j = 0; j < longitudPalabra; j++) {
            if (tolower(texto[i + j]) != tolower(palabra[j])) {
                coincide = 0;
                break;
            }
        }

        if (coincide &&
            (i == 0 || !isalpha(texto[i - 1])) &&
            !isalpha(texto[i + longitudPalabra])) {

            int len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            strcat(resultado, palabra);

            len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            i += longitudPalabra;
        } else {
            int len = strlen(resultado);
            resultado[len] = texto[i];
            resultado[len + 1] = '\0';
            i++;
        }
    }

    printf("\nTexto resaltado:\n%s\n", resultado);
}
void quitarTildes(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if ((unsigned char)texto[i] == 195) {
            switch ((unsigned char)texto[i + 1]) {
                case 161:
                    texto[i] = 'a';
                    break; // á
                case 169:
                    texto[i] = 'e';
                    break; // é
                case 173:
                    texto[i] = 'i';
                    break; // í
                case 179:
                    texto[i] = 'o';
                    break; // ó
                case 186:
                    texto[i] = 'u';
                    break; // ú
                case 177:
                    texto[i] = 'n';
                    break; // ñ
                default:
                    continue;
            }

            for (int j = i + 1; texto[j] != '\0'; j++) {
                texto[j] = texto[j + 1];
            }
        }
    }
}
void listarFrecuenciaPalabras(char texto[]) {
    quitarTildes(texto);

    char palabras[500][50];
    int frecuencia[500] = {0};
    int total = 0;
    char palabra[50];
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            if (j < 49) palabra[j++] = tolower(texto[i]);
        } else if (j > 0) {
            palabra[j] = '\0';
            j = 0;

            int encontrada = 0;
            for (int k = 0; k < total; k++) {
                if (strcmp(palabras[k], palabra) == 0) {
                    frecuencia[k]++;
                    encontrada = 1;
                    break;
                }
            }

            if (!encontrada && total < 500) {
                strcpy(palabras[total], palabra);
                frecuencia[total] = 1;
                total++;
            }
        }
        i++;
    }

    if (j > 0) {
        palabra[j] = '\0';
        int encontrada = 0;
        for (int k = 0; k < total; k++) {
            if (strcmp(palabras[k], palabra) == 0) {
                frecuencia[k]++;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada && total < 500) {
            strcpy(palabras[total], palabra);
            frecuencia[total] = 1;
            total++;
        }
    }
    for (int a = 0; a < total - 1; a++) {
        for (int b = a + 1; b < total; b++) {
            if (frecuencia[b] > frecuencia[a]) {
                int tempF = frecuencia[a];
                frecuencia[a] = frecuencia[b];
                frecuencia[b] = tempF;

                char tempP[50];
                strcpy(tempP, palabras[a]);
                strcpy(palabras[a], palabras[b]);
                strcpy(palabras[b], tempP);
            }
        }
    }

    printf("=== LISTA DE FRECUENCIA DE PALABRAS ===\n");
    printf("%-20s | %s\n", "PALABRA", "FRECUENCIA");
    printf("---------------------+-----------\n");

    for (int i = 0; i < total; i++) {
        printf("%-20s | %d\n", palabras[i], frecuencia[i]);
    }
}
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "cadenas.h"

void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}


void buscarPalabraEnTexto(char texto[], char palabra[]) {
    int posiciones[200];
    char textoCopia[5000];

    strcpy(textoCopia, texto);

    convertirMinusculas(palabra);
    convertirMinusculas(textoCopia);

    int n = buscarUbicaciones(palabra, textoCopia, posiciones);

    printf("\nLa palabra '%s' aparece %d veces y tiene %d letras.\n",
           palabra, n, (int)strlen(palabra));
}

void sustituirPorInversa(char texto[], char palabra[]) {
    char inversa[50];
    char resultado[3000];
    char temp[50];
    int i = 0, j = 0, k = 0;

    invertirCadena(palabra, inversa);
    for (int x = 0; inversa[x] != '\0'; x++) {
        inversa[x] = toupper(inversa[x]);
    }
    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            j = 0;
            while (isalpha(texto[i])) {
                temp[j++] = tolower(texto[i]);
                i++;
            }
            temp[j] = '\0';

            if (strcmp(temp, palabra) == 0) {
                for (int x = 0; inversa[x] != '\0'; x++)
                    resultado[k++] = inversa[x];
            } else {
                for (int x = 0; temp[x] != '\0'; x++)
                    resultado[k++] = temp[x];
            }
            resultado[k++] = ' ';
        } else {
            resultado[k++] = texto[i];
            i++;
        }
    }

    resultado[k] = '\0'; // Final de cadena
    strcpy(texto, resultado);
}


void resaltarPalabraConSimbolo(char texto[], char palabra[], char simbolo) {
    char resultado[5000] = "";
    int i = 0;
    int largo = strlen(palabra);

    while (texto[i] != '\0') {
        int igual = 1;

        for (int j = 0; j < largo; j++) {
            if (tolower(texto[i + j]) != tolower(palabra[j])) {
                igual = 0;
                break;
            }
        }
        // Si coincide y no es parte de otra palabra
        if (igual &&
            (i == 0 || !isalpha(texto[i - 1])) &&
            !isalpha(texto[i + largo])) {

            // Agrega el símbolo, la palabra y el símbolo al resultado
            int len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            strcat(resultado, palabra);

            len = strlen(resultado);
            resultado[len] = simbolo;
            resultado[len + 1] = '\0';

            i += largo;
            } else {

                int len = strlen(resultado);
                resultado[len] = texto[i];
                resultado[len + 1] = '\0';
                i++;
            }
    }

    strcpy(texto, resultado);
}

void quitarTildes(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == (char)195) {
            switch (texto[i + 1]) {
                case (char)161:
                    texto[i] = 'a';
                    break; // á
                case (char)169:
                    texto[i] = 'e';
                    break; // é
                case (char)173:
                    texto[i] = 'i';
                    break; // í
                case (char)179:
                    texto[i] = 'o';
                    break; // ó
                case (char)186:
                    texto[i] = 'u';
                    break; // ú
                case (char)177:
                    texto[i] = 'n';
                    break; // ñ
                default: continue;
            }

            for (int j = i + 1; texto[j] != '\0'; j++) {
                texto[j] = texto[j + 1];
            }
        }
    }
}

void listarFrecuenciaPalabras(char texto[]) {
    quitarTildes(texto); // quitar acentos antes

    char palabras[500][50];
    int frecuencia[500] = {0};
    int total = 0;
    char palabra[50];
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            palabra[j++] = tolower(texto[i]);
        } else if (j > 0) {
            palabra[j] = '\0';
            j = 0;

            int existe = 0;
            for (int k = 0; k < total; k++) {
                if (strcmp(palabras[k], palabra) == 0) {
                    frecuencia[k]++;
                    existe = 1;
                    break;
                }
            }

            if (!existe) {
                strcpy(palabras[total], palabra);
                frecuencia[total] = 1;
                total++;
            }
        }
        i++;
    }

    // Si el texto termina con una palabra sin espacio
    if (j > 0) {
        palabra[j] = '\0';
        int existe = 0;
        for (int k = 0; k < total; k++) {
            if (strcmp(palabras[k], palabra) == 0) {
                frecuencia[k]++;
                existe = 1;
                break;
            }
        }
        if (!existe) {
            strcpy(palabras[total], palabra);
            frecuencia[total] = 1;
            total++;
        }
    }

    // Ordenar de mayor a menor frecuencia (método burbuja)
    for (int a = 0; a < total - 1; a++) {
        for (int b = a + 1; b < total; b++) {
            if (frecuencia[b] > frecuencia[a]) {
                int temp = frecuencia[a];
                frecuencia[a] = frecuencia[b];
                frecuencia[b] = temp;

                char tempPal[50];
                strcpy(tempPal, palabras[a]);
                strcpy(palabras[a], palabras[b]);
                strcpy(palabras[b], tempPal);
            }
        }
    }

    printf("=== FRECUENCIA DE PALABRAS ===\n");
    for (int k = 0; k < total; k++) {
        printf("%-15s -> %d\n", palabras[k], frecuencia[k]);
    }
}

void borrarPalabra(char texto[], char palabra[]) {
    char palabraTemp[50];
    char resultado[3000] = "";
    int i = 0, j = 0;

    for (int k = 0; palabra[k] != '\0'; k++) {
        palabra[k] = tolower(palabra[k]);
    }

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            j = 0;
            while (isalpha(texto[i]) && j < 49) {
                palabraTemp[j++] = tolower(texto[i]);
                i++;
            }
            palabraTemp[j] = '\0';

            // Si no es la palabra que queremos borrar, la copiamos
            if (strcmp(palabraTemp, palabra) != 0) {
                strcat(resultado, palabraTemp);
                strcat(resultado, " ");
            }
        } else {
            i++;
        }
    }

    strcpy(texto, resultado);

    printf("\nTexto modificado (se eliminó '%s'):\n", palabra);
    printf("%s\n", texto);
}
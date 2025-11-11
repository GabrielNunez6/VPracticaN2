#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "cadenas.h"


/*
 * Convierte todos los caracteres de una cadena a minúsculas.
 * Recorre la cadena carácter por carácter y aplica la función tolower()
 * para asegurar que no haya distinción entre mayúsculas y minúsculas
 * en operaciones posteriores, como búsquedas de texto.
 *
 * @param cadena Arreglo de caracteres (string) que será modificado directamente.
 *               Debe estar terminado en '\0'.
 */
void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

/*
* Busca una palabra dentro de un texto y muestra cuántas veces aparece.
* Convierte tanto el texto como la palabra a minúsculas antes de buscar
* para que la comparación no distinga entre mayúsculas y minúsculas.
* También muestra el número de letras de la palabra encontrada.
*
* @param texto  Cadena de caracteres donde se realizará la búsqueda.
* @param palabra Cadena de caracteres que se desea buscar dentro del texto.
*/
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

 /* Sustituye todas las apariciones de una palabra en un texto por su versión invertida en mayúsculas.
 *
 * La función busca palabra por palabra dentro del texto, comparando sin distinguir entre mayúsculas
 * y minúsculas. Cuando encuentra coincidencias exactas con la palabra indicada, la reemplaza por su
 * forma invertida y en mayúsculas. Las demás palabras permanecen iguales.
 *
 * @param texto   Cadena de caracteres que contiene el texto original y donde se realizarán los cambios.
 *                El resultado final se guarda en la misma variable.
 * @param palabra Cadena de caracteres que se desea buscar e invertir en el texto.
 */
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

/* Resalta todas las apariciones de una palabra dentro de un texto
 * rodeándolas con un símbolo específico.
 * La comparación entre la palabra y el texto no distingue entre mayúsculas y minúsculas.
 * Solo se consideran coincidencias completas (no dentro de otras palabras).
 * Cada ocurrencia encontrada se rodea con el símbolo indicado al principio y al final.
 *
 * @param texto   Cadena de caracteres donde se buscará y modificará el contenido.
 *                El texto resultante se almacena en el mismo arreglo.
 * @param palabra Cadena de caracteres que se desea resaltar dentro del texto.
 * @param simbolo Carácter que se colocará antes y después de cada coincidencia encontrada.
 */
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

/*Analiza un texto y muestra la frecuencia de aparición de cada palabra,
 * ordenándolas de mayor a menor frecuencia.
 *
 * Primero elimina los acentos del texto mediante la función quitarTildes().
 * Luego convierte todas las letras a minúsculas para evitar duplicados por diferencias de mayúsculas.
 * Cada palabra se almacena y su número de repeticiones se contabiliza.
 * Finalmente, los resultados se ordenan y se imprimen en formato legible.
 *
 * @param texto Cadena de caracteres que contiene el texto a analizar.
 *              El texto será modificado internamente (se eliminan tildes y se normaliza).
 */
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

/*Elimina todas las apariciones de una palabra específica dentro de un texto.
 *
 * La comparación entre palabras no distingue entre mayúsculas y minúsculas.
 * Cada vez que la palabra buscada aparece, se omite al reconstruir el texto,
 * dejando espacios entre las demás palabras. Al final, se muestra el texto modificado.
 *
 * @param texto   Cadena de caracteres donde se eliminarán las apariciones de la palabra.
 *                El resultado final se almacena en el mismo arreglo.
 * @param palabra Cadena de caracteres que se desea eliminar del texto.
 */
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
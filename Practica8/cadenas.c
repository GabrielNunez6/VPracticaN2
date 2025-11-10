#include <ctype.h>
#include <string.h>

/* Invierte el orden de los caracteres de una cadena y guarda el resultado en otra.
 *
 * Copia los caracteres de la cadena original en orden inverso dentro del arreglo destino.
 * Se asegura de finalizar la cadena resultante con el carácter nulo '\0'.
 *
 * @param primeraCadena   Cadena de caracteres original que se desea invertir.
 * @param cadenaResultado Arreglo donde se almacenará la cadena invertida.
 *                        Debe tener suficiente espacio para contener la cadena completa.
 */
void invertirCadena(char primeraCadena[], char cadenaResultado[]) {
    int longitud = strlen(primeraCadena);

    for (int i = 0; i < longitud; i++) {
        cadenaResultado[i] = primeraCadena[longitud - 1 - i];
    }
    cadenaResultado[longitud] = '\0';
}

/* Cuenta el número total de palabras contenidas en una cadena de texto.
 *
 * Considera como palabra cualquier secuencia continua de letras alfabéticas.
 * Ignora números, signos de puntuación y espacios. Las mayúsculas y minúsculas
 * no afectan el conteo.
 *
 * @param cadena Cadena de caracteres que se desea analizar.
 * @return Número total de palabras encontradas en la cadena.
 */
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

/* Busca todas las apariciones exactas de una palabra dentro de un texto
 * y almacena las posiciones donde comienzan.
 *
 * La comparación no distingue entre mayúsculas y minúsculas.
 * Solo se consideran coincidencias completas (no dentro de otras palabras).
 * Devuelve la cantidad total de coincidencias encontradas.
 *
 * @param palabra    Cadena que se desea buscar dentro del texto.
 * @param texto      Cadena de texto donde se realizará la búsqueda.
 * @param posiciones Arreglo de enteros donde se guardarán las posiciones
 *                   iniciales de cada coincidencia encontrada.
 * @return Número total de apariciones de la palabra en el texto.
 */
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
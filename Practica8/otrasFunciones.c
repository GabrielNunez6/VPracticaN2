#include <ctype.h>
#include <string.h>

void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);

    }
}

void limpiarSaltoLinea(char cadena[]) {
    cadena[strcspn(cadena, "\n")] = '\0';
}
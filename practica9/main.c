#include <stdio.h>
#include <string.h>

int main() {
    char nombre[100];
    char nombreNum[100];
    char linea[500];
    int contador = 1;

    printf("Ingresa el nombre del archivo: ");
    fgets(nombre, 100, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    // Cambiar extensión a .num
    // Buscar el punto de la extensión
    int i, pos = -1;
    int longitud = strlen(nombre);
    for (i = 0; i < longitud; i++) {
        if (nombre[i] == '.') {
            pos = i;
        }
    }

    if (pos != -1) {
        // Copia todo antes del punto
        strncpy(nombreNum, nombre, pos);
        nombreNum[pos] = '\0';
        strcat(nombreNum, ".num");
    } else {
        // Si no tiene punto, solo agregar .num
        strcpy(nombreNum, nombre);
        strcat(nombreNum, ".num");
    }

    // Abrir archivos
    FILE *original = fopen(nombre, "r");
    FILE *nuevo = fopen(nombreNum, "w");

    if (original == NULL) {
        printf("No se pudo abrir el archivo original.\n");
        return 1;
    }

    if (nuevo == NULL) {
        printf("No se pudo crear el archivo numerado.\n");
        fclose(original);
        return 1;
    }

    while (fgets(linea, sizeof(linea), original) != NULL) {
        fprintf(nuevo, "%d: %s", contador, linea);
        contador++;
    }

    fclose(original);
    fclose(nuevo);

    printf("Archivo generado: %s\n", nombreNum);

    return 0;
}
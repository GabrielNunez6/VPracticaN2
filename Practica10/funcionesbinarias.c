//
// Created by usuario on 11/24/2025.
//
#include <stdio.h>
#include <stdlib.h>

#include "registro.h"

/**
 * @brief Guarda todos los registros en un archivo binario.
 *
 * @param registros      Arreglo de registros.
 * @param cantidadActual Cantidad de registros.
 */
void guardarRegistroBinario(Record registros[], int cantidadActual) {
    FILE *archivo;
    archivo = fopen("registros.bin", "wb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar.\n");
        exit(1);
    }

    /* Guardamos primero cuántos registros existen */
    fwrite(&cantidadActual, sizeof(int), 1, archivo);

    /* Ahora guardamos todos los registros */
    fwrite(registros, sizeof(Record), cantidadActual, archivo);

    fclose(archivo);

    printf("Registros guardados correctamente.\n");
}

/**
 * @brief Lee todos los registros almacenados en un archivo binario.
 *
 * @param registros Arreglo donde se almacenarán los registros leídos.
 *
 * @return Cantidad de registros cargados desde el archivo.
 */
int leerRegistrosBinario(Record registros[]) {
    int cantidadLeida;
    FILE *archivo;
    archivo = fopen("registros.bin", "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo registros.bin\n");
        exit(1);
    }

    /* Leemos cuántos registros contiene el archivo */
    fread(&cantidadLeida, sizeof(int), 1, archivo);

    /* Leemos todos los registros */
    fread(registros, sizeof(Record), cantidadLeida, archivo);

    fclose(archivo);

    return cantidadLeida;
}
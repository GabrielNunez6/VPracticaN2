//
// Created by usuario on 11/24/2025.
//
#include <stdio.h>
#include "registro.h"

/**
 * Agrega un nuevo registro al vector.
 *
 * @param registros        Arreglo donde se almacenan los registros.
 * @param cantidadActual   Número actual de registros almacenados.
 * @param capacidadMaxima  Tamaño máximo del arreglo.
 *
 * @return Nueva cantidad de registros después del alta.
 */
int altaRecord(Record registros[], int cantidadActual, int capacidadMaxima) {

    // Verificar si aún hay espacio
    if (cantidadActual >= capacidadMaxima) {
        printf("No es posible agregar más registros.\n");
        return cantidadActual;
    }

    // Solicitar información del nuevo registro
    printf("Ingrese el ID: ");
    scanf("%d", &registros[cantidadActual].id);

    printf("Ingrese el nombre del jugador: ");
    scanf(" %24[^\n]", registros[cantidadActual].nombre);

    printf("Ingrese los puntos obtenidos: ");
    scanf("%d", &registros[cantidadActual].puntos);

    printf("Ingrese la fecha (dd mm aaaa): ");
    scanf("%d %d %d",&registros[cantidadActual].dia, &registros[cantidadActual].mes, &registros[cantidadActual].anio);

    // Aumentar la cantidad
    return cantidadActual + 1;
}

/**
 * Elimina un registro del vector buscando por ID.
 *
 * @param registros       Arreglo de registros.
 * @param cantidadActual  Número actual de registros almacenados.
 * @param idBorrar        ID del registro que se desea eliminar.
 *
 * @return Nueva cantidad de registros después de eliminar.
 */
int bajaRecord(Record registros[], int cantidadActual, int idBorrar) {
    int indice;
    int posicionEncontrada = -1;

    // Buscar el ID dentro del vector
    for (indice = 0; indice < cantidadActual; indice++) {
        if (registros[indice].id == idBorrar) {
            posicionEncontrada = indice;
            break;
        }
    }

    // Si no se encontró el registro
    if (posicionEncontrada == -1) {
        printf("No se encontro un registro con ese ID.\n");
        return cantidadActual;
    }

    // Compactar el vector moviendo todos a la izquierda
    for (indice = posicionEncontrada; indice < cantidadActual - 1; indice++) {
        registros[indice] = registros[indice + 1];
    }

    printf("Registro eliminado correctamente.\n");

    return cantidadActual - 1;
}

/**
 * @brief Modifica los datos de un registro identificado por su ID.
 *
 * @param registros       Arreglo de registros.
 * @param cantidadActual  Número actual de registros.
 * @param idCorregir      ID del registro a modificar.
 */
void corregirRecord(Record registros[], int cantidadActual, int idCorregir) {
    int indice;
    int posicionEncontrada = -1;

    // Buscar registro por ID
    for (indice = 0; indice < cantidadActual; indice++) {
        if (registros[indice].id == idCorregir) {
            posicionEncontrada = indice;
            break;
        }
    }

    if (posicionEncontrada == -1) {
        printf("No esta el registro con ese ID.\n");
        return;
    }

    printf("Nuevo nombre: ");
    scanf(" %24[^\n]", registros[posicionEncontrada].nombre);

    printf("Nuevos puntos: ");
    scanf("%d", &registros[posicionEncontrada].puntos);

    printf("Nueva fecha (dd mm aaaa): ");
    scanf("%d %d %d", &registros[posicionEncontrada].dia, &registros[posicionEncontrada].mes, &registros[posicionEncontrada].anio);

    printf("Se actualizo el registro.\n");
}

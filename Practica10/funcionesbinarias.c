//
// Created by usuario on 11/24/2025.
//
#include <stdio.h>
#include "registro.h"

// Agrega un nuevo registro al vector de registros.
// Parámetros: arreglo de registros, cantidad actual, capacidad máxima.
// Regresa: nueva cantidad de registros.
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
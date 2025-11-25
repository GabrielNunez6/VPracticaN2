#include <stdio.h>
#include "registro.h"
#include "funcionesbinarias.h"
#include "menuRegistro.h"
#include "funcionesRegistros.h"

#define MAX_REGISTROS 100

int main(void) {
    Record registros[MAX_REGISTROS];
    int cantidadRegistros = 0;
    int opcion;
    int idBuscado;
    char nombreArchivo[50];
    int cantidadActual;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                cantidadRegistros = altaRecord(registros, cantidadRegistros, MAX_REGISTROS);
                break;

            case 2:
                printf("Que id quieres eliminar? ");
                scanf("%d", &idBuscado);
                cantidadRegistros = bajaRecord(registros, cantidadRegistros, idBuscado);
                break;

            case 3:
                printf("Cual id quieres corregir?: ");
                scanf("%d", &idBuscado);
                corregirRecord(registros, cantidadRegistros, idBuscado);
                break;

            case 4:
                mostrarTodosRegistros(registros, cantidadRegistros);
                break;

            case 5:
                guardarRegistroBinario(registros, cantidadRegistros);
                break;

            case 6:
                cantidadRegistros = leerRegistrosBinario(registros);
                printf("El total de registros guardados fueron: %d registros.\n", cantidadRegistros);
                break;
        }

    } while (opcion != 0);

    return 0;
}
#include <stdio.h>
#include "registro.h"
#include "funcionesbinarias.h"
#include "menuRegistro.h"

#define MAX_REGISTROS 100

int main(void) {
    Record registros[MAX_REGISTROS];
    int cantidadRegistros = 0;
    int opcion;
    int idBuscado;
    char nombreArchivo[50];

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Dar de alta registro
                cantidadRegistros =
                        altaRecord(registros, cantidadRegistros, MAX_REGISTROS);
                break;
                case 2:
                // Dar de Baja registro
                printf("Ingrese el ID a eliminar: ");
                scanf("%d", &idBuscado);

                cantidadRegistros =
                    bajaRecord(registros, cantidadRegistros, idBuscado);
                break;
        }
    } while (opcion != 0);
}

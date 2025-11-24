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
                // Alta
                cantidadRegistros =
                        altaRecord(registros, cantidadRegistros, MAX_REGISTROS);
                break;
                return 0;
        }
    } while (opcion != 0);
}

#include <stdio.h>
#include "registro.h"
#include "funcionesRegistros.h"

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
    int c;

    if (cantidadActual >= capacidadMaxima) {
        printf("No es posible agregar mas registros.\n");
        return cantidadActual;
    }

    int id;
    do {
        id = leerEntero("Ingrese el ID: ");
        if (idExiste(registros, cantidadActual, id)) {
            printf("Ese ID ya existe. Ingrese uno diferente.\n");
        }
    } while (idExiste(registros, cantidadActual, id));
    registros[cantidadActual].id = id;

    /* === NOMBRE === */
    printf("Ingrese el nombre del jugador: ");
    scanf(" %24[^\n]", registros[cantidadActual].nombre);
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    /* === PUNTOS === */
    registros[cantidadActual].puntos = leerEntero("Ingrese los puntos obtenidos: ");

    /* === FECHA === */
    printf("Ingrese la fecha (dd mm aaaa): ");
    while (scanf("%d %d %d", &registros[cantidadActual].dia, &registros[cantidadActual].mes, &registros[cantidadActual].anio) != 3) {

        printf(" debes ingresar la fecha en el formato que se te pide (dd mm aaaa): ");
        while ((c = getchar()) != '\n' && c != EOF) {}
                 }
    while ((c = getchar()) != '\n' && c != EOF) {}

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
    int i;
    int posicionEncontrada = -1;

    for (i = 0; i < cantidadActual; i++) {
        if (registros[i].id == idBorrar) {
            posicionEncontrada = i;
            break;
        }
    }

    // Si no se encontró el registro
    if (posicionEncontrada == -1) {
        printf("No hay NINGUN registro con ese ID.\n");
        return cantidadActual;
    }

    // Compactar el vector moviendo todos a la izquierda
    for (i = posicionEncontrada; i < cantidadActual - 1; i++) {
        registros[i] = registros[i + 1];
    }

    printf("Se elimino el registro del jugador\n");

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
    int posicionEncontrada = -1;

    for (int i = 0; i < cantidadActual; i++) {
        if (registros[i].id == idCorregir) {
            posicionEncontrada = i;
            break;
        }
    }

    if (posicionEncontrada == -1) {
        printf("No hay ningun jugador con ese id.\n");
        return;
    }

    printf("Nuevo nombre: ");
    scanf(" %24[^\n]", registros[posicionEncontrada].nombre);

    printf("Nuevos puntos: ");
    scanf("%d", &registros[posicionEncontrada].puntos);

    printf("Nueva fecha (dd mm aaaa): ");
    scanf("%d %d %d", &registros[posicionEncontrada].dia, &registros[posicionEncontrada].mes, &registros[posicionEncontrada].anio);

    printf("Informacion corregida.\n");
}


/**
 * @brief Muestra todos los registros almacenados.
 *
 * @param registros       Arreglo de registros.
 * @param cantidadActual  Cantidad de registros almacenados.
 */
void mostrarTodosRegistros(Record registros[], int cantidadActual) {
    if (cantidadActual == 0) {
        printf("Aun no hay jugadores registrados.\n");
        return;
    }
    printf("\n=== LISTA DE REGISTROS ===\n");

    for (int i = 0; i < cantidadActual; i++) {
        printf("\nRegistro %d:\n", i + 1);
        printf(" ID: %d\n", registros[i].id);
        printf(" Nombre: %s\n", registros[i].nombre);
        printf(" Puntos: %d\n", registros[i].puntos);
        printf(" Fecha: %02d/%02d/%04d\n", registros[i].dia, registros[i].mes, registros[i].anio);
    }
}

/**
 * Lee un número entero validado por teclado.
 *
 * @param error Mensaje que se mostrará al usuario.
 * @return Número entero ingresado correctamente.
 */
int leerEntero(char error[]) {
    int numero;
    int c;

    printf("%s", error);

    while (scanf("%d", &numero) != 1) {
        printf("Ingrese un número válido.\n%s", error);

        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    while ((c = getchar()) != '\n' && c != EOF) { }

    return numero;
}

int idExiste(Record registros[], int cantidadActual, int idBuscado) {
    for (int i = 0; i < cantidadActual; i++) {
        if (registros[i].id == idBuscado) {
            return 1;  // existe
        }
    }
    return 0;
}
#include <stdio.h>
#include "aleatorio.h"

/*
 * Llena un vector con la cantidad de dados especificada
 * cada dado recibe un valor aleatorio entre 1 y 6
 */
void tirarDados(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        dados[i] = lanzarDado();
    }
}

/*
 * Muestra en pantalla los valores de todos los dados
 * que contiene el vector
 */
void mostrarDados(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", dados[i]);
    }
    printf("\n");
}

/*
 * Permite relanzar cada dado del vector si el usuario
 * decide hacerlo. Se pregunta dado por dado.
 */
void relanzarDados(int dados[], int cantidad) {
    char opcion;
    for (int i = 0; i < cantidad; i++) {
        printf("Relanzar dado %d (actual=%d)? (s/n): ", i+1, dados[i]);
        scanf(" %c", &opcion);
        if (opcion == 's' || opcion == 'S') {
            dados[i] = lanzarDado();
        }
    }
}

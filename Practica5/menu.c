#include <stdio.h>
#include "menu.h"

// Función que muestra el menú de figuras en pantalla
void mostrarMenu() {
    printf("\n=== MENU DE FIGURAS ===\n");
    printf("a. Rectangulo de asteriscos\n");
    printf("b. Triangulo izq de asteriscos\n");
    printf("c. Triangulo der de asteriscos\n");
    printf("d. Piramide de asteriscos\n");
    printf("e. Piramide de numeros iguales\n");
    printf("f. Piramide numerica decreciente-ascendente\n");
    printf("g. Salir\n");
}

// Función que recibe dos letras (inicio y fin),
// que mediante un ciclo do-while pide al usuario una opción válida y
// regresa la letra elegida
char OpcionLetra(char inicio, char fin) {
    char opcion;
    do {
        printf("\nSelecciona una opcion (%c - %c):\n ", inicio, fin);
        scanf(" %c", &opcion);
        getchar();
    } while (opcion < inicio || opcion > fin);
    return opcion;
}

// Función que recibe dos enteros (inicio y fin),
// que mediante un ciclo do-while pide al usuario un número válido y
// regresa el número elegido
int OpcionNumero(int inicio, int fin) {
    int opcion;
    do {
        printf("Selecciona una opcion (%d - %d):\n ", inicio, fin);
        scanf("%d", &opcion);
    } while (opcion < inicio || opcion > fin);
    return opcion;
}

// Función que recibe alto y largo, que mediante un ciclo externo recorre filas y
// un ciclo interno recorre columnas para imprimir asteriscos
void figura1(int alto, int largo) {
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < largo; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Función que recibe tamaño, que mediante un ciclo externo recorre filas y
// un ciclo interno imprime asteriscos de cada fila para formar un triángulo izquierdo
void figura2(int tamano) {
    for(int i = 0; i <= tamano; i++) {
        for(int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Función que recibe tamaño, que mediante un ciclo externo recorre filas,
// un primer ciclo interno imprime espacios y
// un segundo ciclo interno imprime asteriscos para formar un triángulo derecho
void figura3(int tamano) {
    for (int i = 0; i <= tamano; i++) {
        for (int j = tamano; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

// Función que recibe tamaño, que mediante un ciclo externo recorre filas,
// un primer ciclo interno imprime espacios y
// un segundo ciclo interno imprime asteriscos
// (cantidad impar) para formar una pirámide centrada
void figura4(int tamano) {
    for(int i = 0; i <= tamano; i++) {
        for(int j = 0; j < tamano - i; j++) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Función que recibe tamaño, que mediante un ciclo externo recorre filas,
// un primer ciclo interno imprime espacios,
// un segundo ciclo interno imprime números de izquierda a derecha y
// un tercer ciclo interno imprime números de derecha a izquierda para formar
// una pirámide de números iguales
void figura5(int tamano) {
    for (int i = 0; i <= tamano; i++) {
        for (int j = 30; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        for (int j = 1; j < i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
    printf("\n");
}

// Función que recibe tamaño, que mediante un ciclo externo recorre filas,
// un primer ciclo interno imprime espacios,
// un segundo ciclo interno imprime números decrecientes y
// un tercer ciclo interno imprime números ascendentes para f
// ormar una pirámide numérica decreciente-ascendente
void figura6(int tamano) {
    for (int i = 0; i <= tamano; i++) {
        for (int j = 30; j > i; j--) {
            printf(" ");
        }
        for (int j = i; j >= 1; j--) {
            printf("%d", j);
        }
        for (int j = 2; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}

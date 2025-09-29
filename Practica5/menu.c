#include <stdio.h>
#include "menu.h"

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

char OpcionLetra(char inicio, char fin) {
    char opcion;
    do {
        printf("\nSelecciona una opcion (%c - %c):\n ", inicio, fin);
        scanf("%c", &opcion);
        getchar();
    } while (opcion < inicio || opcion > fin);
    return opcion;
}

int OpcionNumero(int inicio, int fin) {
    char opcion;
    do {
        printf("Selecciona una opcion (%d - %d):\n ", inicio, fin);
        scanf(" %d", &opcion);
    } while (opcion < inicio || opcion > fin);
    return opcion;
}

//Funcion que recibe como parametros el alto y el largo de la figura para despues
//mediante un ciclo for imprimirlos en asteriscos formando un rectangulo
void figura1(int alto, int largo) {
    for(int i = 0; i < alto; i++) {
        for(int j = 0; j < largo; j++) {
            printf("*");
        }
        printf("\n");
    }
}
//funcion que recibe el tamano de un rectangulo que mediante un ciclo for
//lo muestra alineado a la izquierda
void figura2(int tamano) {
    for(int i = 0; i <= tamano; i++) {
        for(int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

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

// Función que recibe el tamaño de un triángulo y lo imprime con asteriscos.
// Usa 3 ciclos for: el primero controla las filas, el segundo imprime espacios
// y el tercero los asteriscos con una multiplicacion deL TAMANO por 2 - 1
//para que se forme la piramide ya que va en numeros impares.
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


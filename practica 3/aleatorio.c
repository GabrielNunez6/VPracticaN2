#include "aleatorio.h"
//
// Created by Cecilia Curlango on 8/26/25.
//
/*
 * Regresa un número entre 1 y 6 como si
 * se lanza un dado de 6 caras.
 */
int lanzarDado() {
    return numeroAleatorio(6) + 1;
}
/*
 * Regresa un número aleatorio en el rango de
 * un valor mínimo a uno máximo sin incluir
 * el máximo.
 */
int numeroAleatorioConRango(int minimo, int maximo) {
    int rango = maximo - minimo;
    return numeroAleatorio(rango) + minimo;
}
/*
 * Regresa un número aleatorio en el rango de
 * 0 a uno máximo, sin incluir el máximo.
 */
int numeroAleatorio(int maximo) {
    // initAleatorio();
    return rand()%maximo;
}

/*
 * Inicializa el generador de números aleatorios.
 */
void initAleatorio() {
    srand(time(NULL));
}
/*
 * Genera un lado de una ficha de dominó
 */
int generaLadoFicha() {
    int lado = numeroAleatorio(7);
    return lado;
}

//Generar un palo aleatorio//
char paloAleatorio(){
    int numero;
    char palo;
    numero=numeroAleatorio(4);
    switch (numero) {
        case 0:
            palo='T';
            break;
        case 1:
            palo='C';
            break;
            case 2:
            palo='P';
            break;
            case 3:
            palo='D';
            break;
    }
    return palo;
}
int numeroCartaAleatorio() {
    int numero;
    numero=numeroAleatorio(13);
    return numero+1;

}

void crearCarta(int numero, char palo) {
    switch (numero) {
        case 1:
            printf("Carta: A");
            break;
            case 11:
            printf("Carta: J ");
            break;
            case 12:
            printf("Carta: Q");
            break;
            case 13:
            printf("Carta: K");
            break;
        default:
            printf("El valor es: %d", numero);

    }
    printf("\n");
    switch (palo) {
        case 'T':
            printf("trebol");
            break;
            case 'C':
            printf("Corazon");
            break;
            case 'P':
            printf("Picas");
            break;
            case 'D':
            printf("Diamante");
            break;

    }
}
bool compararValor(int numero1, int numero2) {

    if (numero1==numero2) {
        printf("True");
        return true;
    } else {
        printf("false");
        return false;
    }
}
bool compararPalo(char palo1, char palo2) {

    if (palo1==palo2) {
        printf("True");
        return true;
    } else {
        printf("false");
        return false;
    }
}
int sumarValor(int numero1, int numero2, int numero3) {
    return numero1+numero2+numero3;
}
void crearCartaCambio(int numero, char palo) {
    switch (numero) {
        case 1:
            printf("Carta: J");
            break;
        case 11:
            printf("Carta: A ");
            break;
        case 12:
            printf("Carta: Q");
            break;
        case 13:
            printf("Carta: K");
            break;
        default:
            printf("El valor es: %d", numero);

    }
    printf("\n");
    switch (palo) {
        case 'T':
            printf("trebol");
            break;
        case 'C':
            printf("Corazon");
            break;
        case 'P':
            printf("Picas");
            break;
        case 'D':
            printf("Diamante");
            break;

    }
}
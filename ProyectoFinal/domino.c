//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include "domino.h"

/*
 * Función: crearMazo
 * ------------------
 * Crea un mazo de dominó doble según el tipo indicado (6, 9 o 12).
 *
 * mazo: arreglo donde se almacenarán las fichas generadas
 * tipo_domino: número máximo de puntos por lado (6, 9 o 12)
 *
 * Retorna: el número total de fichas creadas en el mazo
 */
int crearMazo(Domino mazo[], int tipo_domino) {
    int totalFichas = 0;
    for(int i = 0; i <= tipo_domino; i++) {
        for(int j = i; j <= tipo_domino; j++) {
            mazo[totalFichas].lado1 = i;
            mazo[totalFichas].lado2 = j;
            totalFichas++;
        }
    }
    return totalFichas;
}

/*
 * Función: mezclarMazo
 * --------------------
 * Mezcla aleatoriamente un mazo de dominó usando la función numeroAleatorio().
 *
 * mazo: arreglo con las fichas del mazo a mezclar
 * totalFichas: cantidad total de fichas en el mazo
 */
void mezclarMazo(Domino mazo[], int totalFichas) {
    for(int i = 0; i < totalFichas; i++) {
        int r = numeroAleatorio(totalFichas); // obtiene un índice aleatorio
        Domino temp = mazo[i];
        mazo[i] = mazo[r];
        mazo[r] = temp;
    }
}

/*
 * Función: imprimirMazo
 * ---------------------
 * Muestra en consola todas las fichas del mazo.
 *
 * mazo: arreglo con las fichas a imprimir
 * totalFichas: cantidad total de fichas en el mazo
 */
void imprimirMazo(Domino mazo[], int totalFichas) {
    for(int i = 0; i < totalFichas; i++) {
        printf("[%d|%d] ", mazo[i].lado1, mazo[i].lado2);
    }
    printf("\n");
}
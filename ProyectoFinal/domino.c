//
// Created by usuario on 11/17/2025.
//
#include <stdio.h>
#include "domino.h"

/*
 * Crear el mazo de dominó según el tipo elegido.
 * Devuelve el número total de fichas creadas.
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
 * Mezclar un mazo de dominó de manera aleatoria usando numeroAleatorio()
 */
void mezclarMazo(Domino mazo[], int totalFichas) {
    for(int i = 0; i < totalFichas; i++) {
        int r = numeroAleatorio(totalFichas); // Función de aleatorio.h
        Domino temp = mazo[i];
        mazo[i] = mazo[r];
        mazo[r] = temp;
    }
}

/*
 * Imprimir todas las fichas del mazo (para depuración)
 */
void imprimirMazo(Domino mazo[], int totalFichas) {
    for(int i = 0; i < totalFichas; i++) {
        printf("[%d|%d] ", mazo[i].lado1, mazo[i].lado2);
    }
    printf("\n");
}
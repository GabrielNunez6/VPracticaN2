//
// Created by usuario on 11/17/2025.
//

#ifndef PROYECTOFINAL_DOMINO_H
#define PROYECTOFINAL_DOMINO_H
#include "aleatorio.h"

#define MAX_FICHAS 91

// Estructura para representar una ficha de dominó
typedef struct {
    int lado1;
    int lado2;
} Domino;

// Funciones del módulo
int crearMazo(Domino mazo[], int tipo_domino);
void mezclarMazo(Domino mazo[], int totalFichas);
void imprimirMazo(Domino mazo[], int totalFichas);
#endif //PROYECTOFINAL_DOMINO_H
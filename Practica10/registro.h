//
// Created by usuario on 11/24/2025.
//

#ifndef PRACTICA10_REGISTRO_H
#define PRACTICA10_REGISTRO_H
#define MAX_NOMBRE 25

typedef struct {
    int id;
    char nombre[MAX_NOMBRE + 1];
    int puntos;
    int dia, mes, anio;
} Record;

#endif //PRACTICA10_REGISTRO_H
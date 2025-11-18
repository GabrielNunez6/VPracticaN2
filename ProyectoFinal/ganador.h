//
// Created by usuario on 11/17/2025.
//

#ifndef PROYECTOFINAL_GANADOR_H
#define PROYECTOFINAL_GANADOR_H
#include <time.h>

#include "jugador.h"

typedef struct {
    char nombre[50];
    int paresFormados;
    char fecha[20];
    int anio, dia, mes;
} RegistroGanador;

void guardarGanador(RegistroGanador r);
void mostrarHistorial();
void registrarGanador(Jugador ganador, char nombreArchivo[]);

#endif //PROYECTOFINAL_GANADOR_H
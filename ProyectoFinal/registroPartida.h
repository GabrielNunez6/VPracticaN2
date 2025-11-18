//
// Created by usuario on 11/17/2025.
//

#ifndef PROYECTOFINAL_REGISTROPARTIDA_H
#define PROYECTOFINAL_REGISTROPARTIDA_H
#define MAX_NOMBRE 50

typedef struct {
    char nombreJugador[MAX_NOMBRE];
    int lado1;
    int lado2;
    int lado3;
    int lado4;
} RegistroPar;

void guardarPar(RegistroPar r, char nombreArchivo[]);
void mostrarPartida(char nombreArchivo[]);
void generarNombreArchivo(char nombreArchivo[]);
void reproducirPartida(char nombreArchivo[]);

#endif //PROYECTOFINAL_REGISTROPARTIDA_H
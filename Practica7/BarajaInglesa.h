//
// Created by Cecilia Curlango on 9/9/25.
//

#ifndef ESTRUCTURASCONCARTAS_BARAJAINGLESA_H
#define ESTRUCTURASCONCARTAS_BARAJAINGLESA_H
#include <stdio.h>
#include <stdbool.h>
#include "aleatorio.h"

typedef struct{
    int valor;
    char palo;
}Carta;

void mostrarCarta(Carta carta);
bool compararValor(Carta uno, Carta dos);
Carta generarCartaAleatoria();
int sumarComo1(Carta uno, Carta dos, Carta tres);
int sumarComo11(Carta uno, Carta dos, Carta tres);
void llenarYMezclarBaraja(Carta carta[], int tamano); //FUNCION AÑADIDA


#endif //ESTRUCTURASCONCARTAS_BARAJAINGLESA_H
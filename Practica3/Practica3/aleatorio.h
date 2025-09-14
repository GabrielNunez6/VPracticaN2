//
// Created by Cecilia Curlango on 8/19/25.
//
// Funciones que contienen comportamientos que requiere
// números aleatorios.
#include <stdbool.h>
#include <stdio.h>
#ifndef ALEATORIO_H
#define ALEATORIO_H
#include <stdlib.h>
#include <time.h>
int numeroAleatorio(int maximo);
int numeroAleatorioConRango(int minimo,int maximo);
int lanzarDado();
void initAleatorio();
char paloAleatorio();
int numeroCartaAleatorio();
void crearCarta(int numero, char palo);
bool compararValor(int numero1, int numero2);
bool compararPalo(char palo1, char palo2);
int sumarValor(int numero1, int numero2, int numero3);
void crearCartaCambio(int numero, char palo);
void mostrarParTercia(int numero, char palo);
void mostrarCarta(int numero, char palo);

#endif //ALEATORIO_H
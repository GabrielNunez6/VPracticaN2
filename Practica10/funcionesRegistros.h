//
// Created by usuario on 11/24/2025.
//

#ifndef PRACTICA10_FUNCIONESREGISTROS_H
#define PRACTICA10_FUNCIONESREGISTROS_H
int altaRecord(Record registros[], int cantidadActual, int capacidadMaxima);
void corregirRecord(Record registros[], int cantidadActual, int idCorregir);
int bajaRecord(Record registros[], int cantidadActual, int idBorrar);
void mostrarTodosRegistros(Record registros[], int cantidadActual);
void mostrarTodosRegistros(Record registros[], int cantidadActual);
int leerEntero(char error[]);
int idExiste(Record registros[], int cantidadActual, int idBuscado);

#endif //PRACTICA10_FUNCIONESREGISTROS_H
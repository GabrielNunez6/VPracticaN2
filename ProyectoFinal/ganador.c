//
// Created by usuario on 11/17/2025.

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "ganador.h"

#define ARCHIVO_REGISTRO "historial_lucky20.dat"

void guardarGanador(RegistroGanador r){
    FILE *archivo = fopen(ARCHIVO_REGISTRO,"ab");
    if(archivo != NULL){
        fwrite(&r, sizeof(RegistroGanador), 1, archivo);
        fclose(archivo);
    } else {
        printf("Error al guardar el registro del ganador.\n");
    }
}

void mostrarHistorial(){
    FILE *archivo = fopen(ARCHIVO_REGISTRO,"rb");
    if(archivo != NULL){
        RegistroGanador r;
        printf("\n=== HISTORIAL DE GANADORES ===\n");
        while(fread(&r, sizeof(RegistroGanador), 1, archivo)){
            printf("Nombre: %s, Pares: %d, Fecha: %s\n", r.nombre, r.paresFormados, r.fecha);
        }
        fclose(archivo);
    } else {
        printf("No se pudo abrir el historial.\n");
    }
}
void registrarGanador(Jugador ganador, char nombreArchivo[]) {
    FILE *archivo = fopen(nombreArchivo, "ab"); // Abrir para agregar en binario
    if(archivo == NULL) {
        printf("Error al abrir el archivo de ganadores.\n");
        return;
    }

    RegistroGanador r;
    strcpy(r.nombre, ganador.nombre);
    r.paresFormados = ganador.paresFormados;

    // Obtener fecha actual
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    r.dia = tm_info->tm_mday;
    r.mes = tm_info->tm_mon + 1;
    r.anio = tm_info->tm_year + 1900;

    fwrite(&r, sizeof(RegistroGanador), 1, archivo);
    fclose(archivo);
}
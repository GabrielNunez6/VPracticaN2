//
// Created by usuario on 11/17/2025.
//
// Funciones para manejar el registro de los ganadores del juego Lucky 20.
// Incluye guardar un ganador, mostrar el historial y registrar un ganador
// en un archivo específico de la partida.

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "ganador.h"

#define ARCHIVO_REGISTRO "historial_lucky20.dat" // Archivo global de historial de ganadores

// ------------------------
// Función: guardarGanador
// Guarda un registro de ganador en el archivo global de historial.
// Parámetros:
//   r: estructura RegistroGanador que contiene los datos del ganador
// ------------------------
void guardarGanador(RegistroGanador r){
    FILE *archivo = fopen(ARCHIVO_REGISTRO,"ab"); // Abrir en modo agregar binario
    if(archivo != NULL){
        fwrite(&r, sizeof(RegistroGanador), 1, archivo); // Escribir registro
        fclose(archivo); // Cerrar archivo
    } else {
        printf("Error al guardar el registro del ganador.\n");
    }
}

// ------------------------
// Función: mostrarHistorial
// Muestra todos los registros de ganadores guardados en el archivo
// global de historial.
// ------------------------
void mostrarHistorialTxt() {
    FILE *archivo = fopen("historial_lucky20.dat", "rb");
    if (archivo != NULL) {
        RegistroGanador r;
        FILE *txt = fopen("historial_lucky20.txt", "w");
        if(txt == NULL){ fclose(archivo); return; }

        while(fread(&r, sizeof(RegistroGanador), 1, archivo)) {
            fprintf(txt, "Nombre: %s, Pares: %d, Fecha: %02d/%02d/%04d\n",
                    r.nombre, r.paresFormados, r.dia, r.mes, r.anio);
        }

        fclose(txt);
        fclose(archivo);
        printf("Historial exportado a historial_lucky20.txt\n");
    }
}


// ------------------------
// Función: registrarGanador
// Guarda un ganador en un archivo binario específico de la partida.
// Parámetros:
//   ganador: jugador que ganó la partida
//   nombreArchivo: nombre del archivo donde se guardará el ganador
// ------------------------
void registrarGanador(Jugador ganador, char nombreArchivo[]) {
    FILE *archivo = fopen(nombreArchivo, "ab"); // Abrir para agregar en binario
    if(archivo == NULL) {
        printf("Error al abrir el archivo de ganadores.\n");
        return;
    }

    RegistroGanador r;
    strcpy(r.nombre, ganador.nombre);      // Copiar nombre del jugador
    r.paresFormados = ganador.paresFormados; // Guardar la cantidad de pares formados

    // Obtener fecha actual y guardar (SACADO DE IA)
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); // Puntero permitido para fecha
    r.dia = tm_info->tm_mday;
    r.mes = tm_info->tm_mon + 1;
    r.anio = tm_info->tm_year + 1900;

    fwrite(&r, sizeof(RegistroGanador), 1, archivo); // Escribir en el archivo
    fclose(archivo); // Cerrar archivo
}
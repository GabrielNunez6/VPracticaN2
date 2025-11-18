#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registroPartida.h"

#include "ganador.h"

/*
 * Función: guardarPar
 * -------------------
 * Guarda un par formado por un jugador en un archivo binario de registro de la partida.
 *
 * r: estructura RegistroPar que contiene el nombre del jugador y los valores de las fichas
 * nombreArchivo: nombre del archivo binario donde se guardará el par
 */
void guardarPar(RegistroPar r, char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "ab"); // Abrir archivo en modo agregar binario
    if(archivo != NULL){
        fwrite(&r, sizeof(RegistroPar), 1, archivo); // Guardar el registro
        fclose(archivo);
    } else {
        printf("Error al guardar el par en el archivo.\n");
    }
}

/*
 * Función: mostrarPartida
 * -----------------------
 * Muestra en consola todos los pares guardados de una partida a partir de su archivo binario.
 *
 * nombreArchivo: nombre del archivo binario que contiene los pares de la partida
 */
void mostrarPartida(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "rb");
    if(archivo != NULL){
        RegistroPar r;
        printf("\n=== Desarrollo de la partida ===\n");
        while(fread(&r,sizeof(RegistroPar),1,archivo)){
            printf("Jugador: %s, Par: [%d|%d] + [%d|%d]\n",
                   r.nombreJugador, r.lado1, r.lado2, r.lado3, r.lado4);
        }
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo de la partida.\n");
    }
}

/* (SACADA DE CHATGPT)
 * Función: generarNombreArchivo
 * -----------------------------
 * Genera un nombre único para el archivo de registro de la partida basado en la fecha actual.
 * Si ya existe un archivo con ese nombre, se añade un sufijo incremental (-1, -2, etc.).
 *
 * nombreArchivo: arreglo donde se almacenará el nombre generado
 */
void generarNombreArchivo(char nombreArchivo[]){
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); // Usar puntero permitido para manipular fecha

    // Formato inicial: partidaDDMMYYYY.bin
    strftime(nombreArchivo, 100, "partida%d%m%Y.bin", tm_info);

    FILE *archivo = fopen(nombreArchivo, "rb");
    int contador = 1;
    while (archivo != NULL){
        fclose(archivo);
        // Añadir sufijo incremental si ya existe archivo
        sprintf(nombreArchivo, "partida%02d%02d%04d-%d.bin",
                tm_info->tm_mday,
                tm_info->tm_mon + 1,
                tm_info->tm_year + 1900,
                contador);
        archivo = fopen(nombreArchivo, "rb");
        contador++;
    }
}

/*
 * Función: reproducirPartida
 * --------------------------
 * Reproduce en consola la partida mostrando todos los pares formados por cada jugador.
 * @param
 * nombreArchivo: nombre del archivo binario que contiene los pares de la partida
 */
void reproducirPartida(char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo,"rb");
    if(archivo != NULL){
        RegistroPar r;
        printf("\n=== Reproducción de la partida: %s ===\n", nombreArchivo);
        while(fread(&r,sizeof(RegistroPar),1,archivo)){
            printf("Jugador: %s formó el par [%d|%d] + [%d|%d]\n",
                   r.nombreJugador, r.lado1, r.lado2, r.lado3, r.lado4);
        }
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo de la partida.\n");
    }
}

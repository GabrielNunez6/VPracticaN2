#include <stdio.h>
#include <string.h>
#include <time.h>
#include "registroPartida.h"

// Guardar un par en el archivo binario
void guardarPar(RegistroPar r, char nombreArchivo[]){
    FILE *archivo = fopen(nombreArchivo, "ab");
    if(archivo != NULL){
        fwrite(&r, sizeof(RegistroPar), 1, archivo);
        fclose(archivo);
    } else {
        printf("Error al guardar el par en el archivo.\n");
    }
}

// Mostrar todos los pares guardados de la partida
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

// Genera un nombre de archivo basado en la fecha actual
void generarNombreArchivo(char nombreArchivo[]){
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); // permitido usar puntero solo para fecha

    strftime(nombreArchivo, 100, "partida%d%m%Y.bin", tm_info);

    FILE *archivo = fopen(nombreArchivo, "rb");
    int contador = 1;
    while (archivo != NULL){
        fclose(archivo);
        sprintf(nombreArchivo, "partida%02d%02d%04d-%d.bin",
                tm_info->tm_mday,
                tm_info->tm_mon + 1,
                tm_info->tm_year + 1900,
                contador);
        archivo = fopen(nombreArchivo, "rb");
        contador++;
    }
}

// Reproducir una partida desde el archivo
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
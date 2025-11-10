#include <stdio.h>
#include <string.h>
#include "cadenas.h"
#include "otrasFunciones.h"

void mostrarMenu() {
    printf("\n=== MENU DE OPERACIONES ===\n");
    printf("1. Buscar palabra en texto\n");
    printf("2. Sustituir palabra por su inversa en mayusculas\n");
    printf("3. Resaltar palabra con simbolo\n");
    printf("4. Listar frecuencia de palabras\n");
    printf("5. Borrar palabra\n");
    printf("0. Salir\n");
}

void ejecutarMenu() {
    char textoOriginal[3000] =
        "La historia de Linux se remonta a 1991, cuando un estudiante finlandés llamado Linus Torvalds comenzó a desarrollar un sistema operativo inspirado en UNIX en su tiempo libre. "
        "Torvalds liberó la primera versión de Linux al público en septiembre de 1991. Desde entonces, Linux se ha convertido en uno de los sistemas operativos más populares y utilizados en todo el mundo.\n\n"
        "Las distribuciones de Linux son diferentes versiones del sistema operativo, que pueden variar en su estructura, configuración y paquetes de software incluidos. "
        "Algunas distribuciones de Linux populares incluyen Debian, Ubuntu, Fedora, CentOS, Arch Linux, entre otras. Cada distribución tiene su propio enfoque y objetivos, lo que significa que pueden ser más adecuadas para diferentes casos de uso y tipos de usuarios.\n\n"
        "La estructura de Linux se basa en el núcleo o kernel del sistema, que es el componente central que gestiona los recursos del sistema, como la memoria, los dispositivos y las aplicaciones. "
        "Además, Linux utiliza un enfoque de archivo único, en el que todo en el sistema es un archivo o directorio que se puede acceder y manipular a través del sistema de archivos.\n\n"
        "El sistema de archivos de Linux también tiene una estructura jerárquica, comenzando en la raíz del sistema, que se indica con una barra diagonal (/). "
        "A partir de ahí, cada directorio se ubica en una ruta descendente, con el nombre del directorio seguido de una barra diagonal. "
        "Algunos de los directorios importantes incluyen /bin (binarios del sistema), /usr (programas y recursos para usuarios), /etc (archivos de configuración del sistema) y /home (directorios personales de usuario).\n\n"
        "Linux es un sistema operativo de código abierto que ha sido desarrollado y mejorado por una comunidad global de programadores y usuarios durante décadas. "
        "Existen muchas distribuciones de Linux, cada una con sus propias características y objetivos, y la estructura y el sistema de archivos de Linux se basan en un enfoque de archivo único y una estructura jerárquica.";

    char palabra[100];
    int posiciones[50];
    int opcion;
    char texto[3000];
    char simbolo;

    strcpy(texto, textoOriginal);

    do {
        mostrarMenu();
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpia el salto de línea

        switch (opcion) {
            case 1:
                strcpy(texto, textoOriginal);
                printf("Palabra a buscar: ");
                scanf("%s", palabra);
                buscarPalabraEnTexto(texto, palabra);
                break;
            case 2:
                strcpy(texto, textoOriginal);
                printf("Palabra a sustituir: ");
                scanf("%s", palabra);
                convertirMinusculas(palabra);
                sustituirPorInversa(texto, palabra);
                printf("\nTexto modificado:\n%s\n", texto);
                break;
            case 3:
                strcpy(texto, textoOriginal);
                printf("Palabra a resaltar: ");
                scanf("%s", palabra);
                printf("Símbolo: ");
                scanf(" %c", &simbolo);
                resaltarPalabraConSimbolo(texto, palabra, simbolo);
                printf("\nTexto resaltado:\n%s\n", texto);
                break;
            case 4:
                strcpy(texto, textoOriginal);
                listarFrecuenciaPalabras(texto);
                break;
            case 5:
                strcpy(texto, textoOriginal);
                printf("Palabra a borrar: ");
                fgets(palabra, sizeof(palabra), stdin);
                palabra[strcspn(palabra, "\n")] = '\0';
                borrarPalabra(texto, palabra);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 0);
}
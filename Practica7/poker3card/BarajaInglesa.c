//
// Created by Cecilia Curlango on 9/9/25.
//
#include "BarajaInglesa.h"
/*
 * Recibe una carta y la muestra
 */
void mostrarCarta(Carta carta) {
    char elValor;
    switch (carta.valor) {
        case 1:
            elValor = 'A';
            printf("%c %c",elValor,carta.palo);
            break;
        case 11:
            elValor = 'J';
            printf("%c %c",elValor,carta.palo);
            break;
        case 12:
            elValor = 'Q';
            printf("%c %c",elValor,carta.palo);
            break;
        case 13:
            elValor = 'K';
            printf("%c %c",elValor,carta.palo);
            break;
        default:
            printf("%d %c",carta.valor,carta.palo);
            break;
    }
}
/*
 * Escribe una función que reciba
 * dos cartas de una baraja inglesa
 * y regrese true si ambas cartas
 * tienen el mismo valor y false si no.
*/
bool compararValor(Carta uno, Carta dos) {
    bool respuesta = true;
    if (uno.valor != dos.valor) {
        respuesta = false;
    }
    return respuesta;
}

/*
 * Generar una carta de baraja inglesa aleatoria.
 */
Carta generarCartaAleatoria() {
    Carta cartaNueva;
    // generar el valor entre 1 - 13
    cartaNueva.valor = numeroAleatorioConRango(1,13);
    // generar el palo entre 1 - 4 (CDTP)
    int disquePalo = numeroAleatorioConRango(1,4);
    // traducir el disque palo a un palo
    switch (disquePalo) {
        case 1:
            cartaNueva.palo = 'C';
            break;
        case 2:
        cartaNueva.palo = 'D';
            break;
        case 3:
            cartaNueva.palo = 'T';
            break;
        case 4:
            cartaNueva.palo = 'P';
            break;
    }
    return cartaNueva;
}
/*
 * Escribe una función que reciba tres cartas
 * de una baraja inglesa y regrese la suma
 * de estas.
 * Si alguna carta es un A,
 * la debe tomar con un valor de 1.
 */
int sumarComo1(Carta uno, Carta dos, Carta tres) {
    int suma = 0;
    // suma = uno.valor + dos.valor + tres.valor;
    suma = suma + uno.valor;
    suma += dos.valor;
    suma += tres.valor;
    return suma;
}
/*
 * Escribe una función que reciba tres cartas
 * de una baraja inglesa y regrese la suma
 * de estas.
 * Si alguna carta es un A,
 * la debe tomar con un valor de 11.
 */
int sumarComo11(Carta uno, Carta dos, Carta tres) {
    int suma = 0;
    // operador ternario ? :
//    if (uno.valor==1) {
//        suma += 11;
//    } else {
//        suma += uno.valor;
//    }
//    int valor = uno.valor==1 ? 11 : uno.valor;

    suma += (uno.valor==1 ? 11 : uno.valor);
    suma += dos.valor==1 ? 11 : dos.valor;
    suma += tres.valor==1 ? 11 : tres.valor;
    return suma;
}


void llenarYMezclarBaraja(Carta carta[], int tamano) {
    char palos[4] = {'C', 'D', 'T', 'P'};
    int contador = 0;
    //Llenar la baraja inglesa
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            carta[contador].valor = j;
            carta[contador].palo = palos[i];
            contador++;
        }
    }
    //Mezclar las 52 cartas de la baraja inglesa
    for (int i = 0; i < tamano; i++) {
        int k = numeroAleatorio(tamano);
        Carta temp = carta[i];
        carta[i] = carta[k];
        carta[k] = temp;
    }
}

int retirarCartas(Carta mazo[], int tamano, Carta mano[]) {
    if (tamano<3) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        mano[i] = mazo[i];
    }
    for (int i = 3; i < tamano; i++) {
        mazo[i] = mazo[i-3];
    }
    return tamano-3;
}
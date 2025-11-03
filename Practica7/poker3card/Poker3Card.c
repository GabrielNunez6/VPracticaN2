#include "Poker3Card.h"
#include <stdbool.h>

/**
 *
 * Esta función verifica si la mano contiene un "Three of a Kind".
 * Ocurre cuando las tres cartas tienen el mismo valor.
 *
 * @param mano vector de 3 cartas que representa la mano.
 * @return true si las tres cartas tienen el mismo valor, false en caso contrario.
 */
bool esThreeOfAKind(Carta mano[3]) {
    return (mano[0].valor == mano[1].valor && mano[1].valor == mano[2].valor);
}

/**
 *
 * Esta función verifica si la mano contiene un "Flush".
 * Ocurre cuando las tres cartas tienen el mismo palo.
 * @param mano Arreglo de 3 cartas que representa la mano.
 * @return true si las tres cartas tienen el mismo palo, false en caso contrario.
 */
bool esFlush(Carta mano[3]) {
    return (mano[0].palo == mano[1].palo && mano[1].palo == mano[2].palo);
}

/**
 *
 * Esta función verifica si la mano contiene un "Straight".
 * Ocurre cuando las tres cartas son consecutivas en valor, sin importar el palo.
 * @param mano vector de 3 cartas que representa la mano.
 * @return true si las cartas son consecutivas, false en caso contrario.
 */
bool esStraight(Carta mano[3]) {
    int a = mano[0].valor, b = mano[1].valor, c = mano[2].valor;

    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    return (b == a + 1 && c == b + 1);
}

/**
 *
 * Esta función verifica si la mano contiene un "Straight Flush".
 * Ocurre cuando las tres cartas son consecutivas y además del mismo palo.
 *
 * @param mano Arreglo de 3 cartas que representa la mano.
 * @return true si las cartas forman un straight flush, false en caso contrario.
 */
bool esStraightFlush(Carta mano[3]) {
    return esStraight(mano) && esFlush(mano);
}


/**
 *
 * Esta función determina si el vector de tres cartas recibido
 * contiene exactamente un par ("one pair"), es decir, dos cartas
 * con el mismo valor y una diferente.
 * @param mano Arreglo de 3 elementos de tipo Carta.
 * @return true si la mano contiene exactamente un par, false en caso contrario.
 */
bool esOnePair(Carta mano[3]) {
    int iguales = 0;

    if (mano[0].valor == mano[1].valor)
        iguales++;
    if (mano[0].valor == mano[2].valor)
        iguales++;
    if (mano[1].valor == mano[2].valor)
        iguales++;

    return (iguales == 1);
}

/**
 *
 * Esta función identifica y devuelve la carta con el valor más alto
 * dentro de un arreglo de tres cartas.
 * @param mano Arreglo de 3 elementos de tipo Carta.
 * @return La estructura Carta que tiene el valor más alto.
 */
Carta esHighCard(Carta mano[3]) {
    Carta mayor = mano[0];
    for (int i = 1; i < 3; i++) {
        if (mano[i].valor > mayor.valor) {
            mayor = mano[i];
        }
    }
    return mayor;
}
/**
 * Esta funcion Asigna un valor numérico a la mano según su categoría.
 * Straight Flush > Three of a Kind > Straight > Flush > One Pair > High Card
 *
 * @param mano vector de 3 cartas que representa la mano.
 * @return Valor numérico de la mano para comparaciones.
 */
int valorMano(Carta mano[3]) {
    if (esStraightFlush(mano))
        return 6;
    if (esThreeOfAKind(mano))
        return 5;
    if (esStraight(mano))
        return 4;
    if (esFlush(mano))
        return 3;
    if (esOnePair(mano))
        return 2;
    return 1;
}
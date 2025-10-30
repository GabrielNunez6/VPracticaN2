#include "Poker3Card.h"
#include <stdbool.h>


bool esThreeOfAKind(Carta mano[3]) {
    return (mano[0].valor == mano[1].valor && mano[1].valor == mano[2].valor);
}

bool esFlush(Carta mano[3]) {
    return (mano[0].palo == mano[1].palo && mano[1].palo == mano[2].palo);
}

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
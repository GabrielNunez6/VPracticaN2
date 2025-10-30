#ifndef Poker3Card_h
#define Poker3Card_h

#include <stdbool.h>
#include "BarajaInglesa.h"

bool esThreeOfAKind(Carta mano[3]);
bool esStraight(Carta mano[3]);
bool esFlush(Carta mano[3]);
bool esStraightFlush(Carta mano[3]);
bool esOnePair(Carta mano[3]);
bool esHighCard(Carta mano[3]);

#endif


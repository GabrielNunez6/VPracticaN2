#include <stdio.h>

#include "aleatorio.h"


int main() {
    initAleatorio();

    int n1 = numeroCartaAleatorio();
    char p1 = paloAleatorio();
    int n2 = numeroCartaAleatorio();
    char p2 = paloAleatorio();
    int n3 = numeroCartaAleatorio();
    char p3 = paloAleatorio();
    int n4 = numeroCartaAleatorio();
    char p4 = paloAleatorio();
    int n5 = numeroCartaAleatorio();
    char p5 = paloAleatorio();

    printf("Cartas generadas:\n");
    printf("Carta 1: ");
    mostrarCarta(n1, p1);
    printf("Carta 2: ");
    mostrarCarta(n2, p2);
    printf("Carta 3: ");
    mostrarCarta(n3, p3);
    printf("Carta 4: ");
    mostrarCarta(n4, p4);
    printf("Carta 5: ");
    mostrarCarta(n5, p5);
    printf("\n");

    if (n1 == n2 || n1 == n3 || n1 == n4 || n1 == n5) {
        printf("Par de ");
        mostrarCarta(n1, p1);
    }
    if (n2 == n3 || n2 == n4 || n2 == n5) {
        printf("Par de ");
        mostrarCarta(n2, p2);
    }
    if (n3 == n4 || n3 == n5) {
        printf("Par de ");
        mostrarCarta(n3, p3);
    }
    if (n4 == n5) {
        printf("Par de ");
        mostrarCarta(n4, p4);
    }


    if ((n1 == n2 && n1 == n3) || (n1 == n2 && n1 == n4) || (n1 == n2 && n1 == n5) ||
      (n1 == n3 && n1 == n4) || (n1 == n3 && n1 == n5) || (n1 == n4 && n1 == n5)) {
        printf("Tercia de ");
        mostrarCarta(n1, p1);
      }
    if ((n2 == n3 && n2 == n4) || (n2 == n3 && n2 == n5) || (n2 == n4 && n2 == n5)) {
        printf("Tercia de ");
        mostrarCarta(n2, p2);
    }
    if (n3 == n4 && n3 == n5) {
        printf("Tercia de ");
        mostrarCarta(n3, p3);
    }

    return 0;
}

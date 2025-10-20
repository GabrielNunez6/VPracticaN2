#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();

    int sumFours = 0, sumFives = 0, sumSixes = 0, sumStraights = 0;
    int sumFull = 0, sumChoice = 0, sumBalut = 0;
    int fours[4], fives[4], sixes[4];
    int straights[4], fullHouse[4], choice[4], baluts[4];

    char nombre[50];

    printf("Ingresa el nombre del jugador: ");
    scanf("%s", nombre);

    // Generar valores aleatorios para 4 rondas
    for (int i = 0; i < 4; i++) {
        fours[i] = numeroAleatorioConRango(0, 6) * 4;
        fives[i] = numeroAleatorioConRango(0, 6) * 5;
        sixes[i] = numeroAleatorioConRango(0, 6) * 6;

        int s = numeroAleatorioConRango(0, 3);
        if (s == 1) {
            straights[i] = 15;
        } else if (s == 2) {
            straights[i] = 20;
        } else {
            straights[i] = 0;
        }

        if (numeroAleatorioConRango(0, 2)) {
            fullHouse[i] = numeroAleatorioConRango(10, 31);
        } else {
            fullHouse[i] = 0;
        }

        choice[i] = numeroAleatorioConRango(5, 31);
        baluts[i] = numeroAleatorioConRango(0, 2) ? 50 : 0;
    }

    // Totales por ronda
    int totalRonda[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        totalRonda[i] = fours[i] + fives[i] + sixes[i] + straights[i] +
                        fullHouse[i] + choice[i] + baluts[i];
    }
    int totalScoreFinal = 0;
    for (int i = 0; i < 4; i++) totalScoreFinal += totalRonda[i];

    // Suma de cada categoría

    for (int i = 0; i < 4; i++) {
        sumFours += fours[i];
        sumFives += fives[i];
        sumSixes += sixes[i];
        sumStraights += straights[i];
        sumFull += fullHouse[i];
        sumChoice += choice[i];
        sumBalut += baluts[i];
    }
    // ---------------- POINTS por categoría ----------------
    int pointsFours = 0;
    if (sumFours >= 52)
        pointsFours = 2;

    int pointsFives = 0;
    if (sumFives >= 65)
        pointsFives = 2;

    int pointsSixes = 0;
    if (sumSixes >= 78)
        pointsSixes = 2;

    // STRAIGHT: 4 puntos
    int pointsStraights = 0;
    int allStraight = 1;

    for (int i = 0; i < 4; i++) {
        if (straights[i] == 0) {
            allStraight = 0;
        }
    }
    if (allStraight)
        pointsStraights = 4;

    // FULLHOUSE: 3 puntos
    int pointsFull = 0;
    if (sumFull > 0)
        pointsFull = 3;

    // CHOICE: 2 puntos
    int pointsChoice = 0;
    if (sumChoice >= 100)
        pointsChoice = 2;

    //TOTAL SCORE
    int bonusPoints = 0;
    if (totalScoreFinal < 300) {
        bonusPoints = -2;
    } else if (totalScoreFinal < 350) {
        bonusPoints = -1;
    } else if (totalScoreFinal < 400) {
        bonusPoints = 0;
    } else if (totalScoreFinal < 450) {
        bonusPoints = 1;
    } else if (totalScoreFinal < 500) {
        bonusPoints = 2;
    } else if (totalScoreFinal < 550) {
        bonusPoints = 3;
    } else if (totalScoreFinal < 600) {
        bonusPoints = 4;
    } else if (totalScoreFinal < 650) {
        bonusPoints = 5;
    } else {
        bonusPoints = 6;
    }

    int totalPointsFinal = pointsFours + pointsFives + pointsSixes + pointsStraights + pointsFull + pointsChoice + bonusPoints;

    return 0;
}






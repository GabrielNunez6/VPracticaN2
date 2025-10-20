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
    // ====================== IMPRESIÓN DE LA HOJA ======================
    printf("=====================================================\n");
    printf("                       BALUT                         \n");
    printf("NAME: %s \n", nombre);
    printf("=====================================================\n\n");

    printf("          |  R1 |  R2 |  R3 |  R4 | SCORE | POINTS\n");
    printf("----------------------------------------------------\n");
    printf("FOURS     | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           fours[0], fours[1], fours[2], fours[3], sumFours, pointsFours);
    printf("FIVES     | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           fives[0], fives[1], fives[2], fives[3], sumFives, pointsFives);
    printf("SIXES     | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           sixes[0], sixes[1], sixes[2], sixes[3], sumSixes, pointsSixes);
    printf("STRAIGHT  | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           straights[0], straights[1], straights[2], straights[3], sumStraights, pointsStraights);
    printf("FULLHOUSE | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           fullHouse[0], fullHouse[1], fullHouse[2], fullHouse[3], sumFull, pointsFull);
    printf("CHOICE    | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           choice[0], choice[1], choice[2], choice[3], sumChoice, pointsChoice);
    printf("BALUT     | %3d | %3d | %3d | %3d |  %3d  |  %2d\n",
           baluts[0], baluts[1], baluts[2], baluts[3], sumBalut, 0);

    printf("----------------------------------------------------\n");
    printf("TOTAL SCORE                         %3d   |\n", totalScoreFinal);
    printf("TOTAL POINTS                              |  %3d\n", totalPointsFinal);
    printf("====================================================\n");
    return 0;
}






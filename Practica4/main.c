#include <stdio.h>
#include "aleatorio.h"
#include "extension.h"

int main() {
    initAleatorio();

    float lado1, lado2, lado3;
    float lado1Mayor1 = 0, lado2Mayor1 = 0, lado3Mayor1 = 0, areaMayor1 = 0;
    float lado1Mayor2 = 0, lado2Mayor2 = 0, lado3Mayor2 = 0, areaMayor2 = 0;
    float lado1Mayor3 = 0, lado2Mayor3 = 0, lado3Mayor3 = 0, areaMayor3 = 0;

    for (int i = 1; i <= 10; i++) {
        int intentos = 0;
        do {
            lado1 = numeroAleatorioConRango(1, 50);
            lado2 = numeroAleatorioConRango(1, 50);
            lado3 = numeroAleatorioConRango(1, 50);
            intentos++;
        } while (!esTriangulo(lado1, lado2, lado3));

        float area = areaTriangulo(lado1, lado2, lado3);
        float perimetro = perimetroTriangulo(lado1, lado2, lado3);

        printf("Triangulo %d:\n", i);
        printf("  Lados: (%.f, %.f, %.f)\n", lado1, lado2, lado3);
        if (esTrianguloEquilatero(lado1, lado2, lado3)) {
            printf("  Tipo: Equilatero\n");
        } else if (esTrianguloIsosceles(lado1, lado2, lado3)) {
            printf("  Tipo: Isosceles\n");
        } else if (esTrianguloEscaleno(lado1, lado2, lado3)) {
            printf("  Tipo: Escaleno\n");
        }
        printf("  perimetro: %.2f\n", perimetro);
        printf("  area: %.2f\n", area);
        printf("  intentos: %d\n", intentos);

        if (area > areaMayor1) {
            areaMayor3 = areaMayor2;
            lado1Mayor3 = lado1Mayor2;
            lado2Mayor3 = lado2Mayor2;
            lado3Mayor3 = lado3Mayor2;

            areaMayor2 = areaMayor1;
            lado1Mayor2 = lado1Mayor1;
            lado2Mayor2 = lado2Mayor1;
            lado3Mayor2 = lado3Mayor1;

            areaMayor1 = area;
            lado1Mayor1 = lado1;
            lado2Mayor1 = lado2;
            lado3Mayor1 = lado3;
        } else if (area > areaMayor2) {
            areaMayor3 = areaMayor2;
            lado1Mayor3 = lado1Mayor2;
            lado2Mayor3 = lado2Mayor2;
            lado3Mayor3 = lado3Mayor2;

            areaMayor2 = area;
            lado1Mayor2 = lado1;
            lado2Mayor2 = lado2;
            lado3Mayor2 = lado3;
        } else if (area > areaMayor3) {
            areaMayor3 = area;
            lado1Mayor3 = lado1;
            lado2Mayor3 = lado2;
            lado3Mayor3 = lado3;
        }
    }

    printf("=== Los 3 triangulos con el area mas grande ===\n");
    printf("TOP 1 con Lados %.2f, %.2f, %.2f y area: %.2f\n", lado1Mayor1, lado2Mayor1, lado3Mayor1, areaMayor1);
    printf("TOP 2 con Lados %.2f, %.2f, %.2f y area: %.2f\n", lado1Mayor2, lado2Mayor2, lado3Mayor2, areaMayor2);
    printf("TOP 3 con Lados %.2f, %.2f, %.2f y area: %.2f\n", lado1Mayor3, lado2Mayor3, lado3Mayor3, areaMayor3);

    return 0;
}

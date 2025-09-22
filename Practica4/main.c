#include <stdio.h>
#include "aleatorio.h"
#include "extension.h"

int main() {
    initAleatorio();
    float lado1, lado2, lado3;
    for(int i = 1; i <= 10; i++) {
        int intentos=0;
        do {
            lado1 = numeroAleatorioConRango(1, 50);
            lado2 = numeroAleatorioConRango(1, 50);
            lado3 = numeroAleatorioConRango(1, 50);
            intentos++;
        } while (!esTriangulo(lado1, lado2, lado3));

        float area = areaTriangulo(lado1, lado2, lado3);
        float perimetro = perimetroTriangulo(lado1, lado2, lado3);

        printf("Triangulo %d:\n", i);
        printf("  Lados: %.f, %.f, %.f\n", lado1, lado2, lado3);

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
    }

    return 0;
}


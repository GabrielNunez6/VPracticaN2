#include "extension.h"
#include <math.h>

// Verifica si los lados forman un triángulo
bool esTriangulo(float lado1, float lado2, float lado3) {
    return (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1);
}

// Equilátero: todos los lados iguales
bool esTrianguloEquilatero(float lado1, float lado2, float lado3) {
    return (lado1 == lado2 && lado2 == lado3);
}

// Escaleno: todos los lados distintos y válido
bool esTrianguloEscaleno(float lado1, float lado2, float lado3) {
    return esTriangulo(lado1, lado2, lado3) && (lado1 != lado2 && lado2 != lado3 && lado1 != lado3);
}

// Isósceles: al menos dos lados iguales y válido
bool esTrianguloIsosceles(float lado1, float lado2, float lado3) {
    return esTriangulo(lado1, lado2, lado3) && ((lado1 == lado2 && lado1 != lado3) || (lado1 == lado3 && lado1 != lado2) || (lado2 == lado3 && lado2 != lado1));
}

// Calcula el área usando fórmula de Herón
float areaTriangulo(float lado1, float lado2, float lado3) {
    float s = (lado1 + lado2 + lado3) / 2;
    return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
}

// Calcula el perímetro
float perimetroTriangulo(float lado1, float lado2, float lado3) {
    return lado1 + lado2 + lado3;
}

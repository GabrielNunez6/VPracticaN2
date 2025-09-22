#ifndef EXTENSION_H
#define EXTENSION_H

#include <stdbool.h>

// Funciones para triángulos
bool esTriangulo(float lado1, float lado2, float lado3);
bool esTrianguloEquilatero(float lado1, float lado2, float lado3);
bool esTrianguloIsosceles(float lado1, float lado2, float lado3);
bool esTrianguloEscaleno(float lado1, float lado2, float lado3);
float areaTriangulo(float lado1, float lado2, float lado3);
float perimetroTriangulo(float lado1, float lado2, float lado3);

#endif

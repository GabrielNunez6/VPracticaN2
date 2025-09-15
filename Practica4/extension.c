//
// Created by Gabriel Nunez Saldana on 9/15/2025.
//

//función que reciba la medida de los lados de un triángulo
//y regrese la medida de su perímetro.

float perimetroTriangulo(float lado1, float lado2, float lado3) {
    return lado1 + lado2 + lado3;
}
//función que reciba la medida de los lados de un triángulo y
//regresa true si los lados forman un triángulo y false si no
bool esTriangulo(float lado1, float lado2, float lado3) {
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) { //La suma de dos lados debe ser mayor al lado restante
        return true;
    } else {
        return false;
    }
}
//Escribe una función que reciba la medida de los lados
//de un triángulo y regresa true si forman un triángulo equilátero.
bool esTrianguloEquilatero(float lado1, float lado2, float lado3) {
    if (lado1==lado2 && lado2==lado3) {
        return true;
    }
}
//Escribe una función que reciba la medida de los lados
//de un triángulo y regresa true si forman un triángulo escaleno
bool esTrianguloEscaleno(float lado1, float lado2, float lado3) {
    if ((lado1 != lado2 && lado2 != lado3 && lado1 != lado3) && (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1)) {
        return true;
        }
}
bool esTrianguloIsosceles(float lado1, float lado2, float lado3) {
    if ((lado1==lado2 && lado1==lado3 && lado2==lado3) && (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1)){
    return true;
}
}
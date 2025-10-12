
//1)
int sumaSiIgualesVectores(int numeros[], int tamaño) {
    for (int i = 1; i < tamaño; i++) {
        if (numeros[i] != numeros[0])
            return 0;
    }
    int suma = 0;
    for (int i = 0; i < tamaño; i++)
        suma += numeros[i];

    return suma;
}

//2)

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
int sumaSiTresIgualesVectores(int numeros[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        int contador = 0;
        for (int j = 0; j < tamaño; j++) {
            if (numeros[j] == numeros[i]) {
                contador++;
            }
        }
        if (contador >= 3) {
            int suma = 0;
            for (int k = 0; k < tamaño; k++) {
                if (numeros[k] == numeros[i]) {
                    suma += numeros[k];
                }
            }
            return suma; // regresamos la suma
        }
    }
}

//3)
int sumaSiDosIgualesVectores(int numeros[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        int contador = 0;
        for (int j = 0; j < tamaño; j++) {
            if (numeros[j] == numeros[i])
                contador++;
        }
        if (contador >= 2) {
            int suma = 0;
            for (int k = 0; k < tamaño; k++) {
                if (numeros[k] == numeros[i])
                    suma += numeros[k];
            }
            return suma;
        }
    }
    return 0;
}

//4)
int sumaSiSecuenciaVectores(int numeros[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i < tamaño; i++) {
        if (numeros[i] != numeros[i - 1] + 1) {
            return 0;
        }
    }
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += numeros[i];
    }
    return suma;
}

//5)
int fullHouse(int numeros[], int tamano) {
    int i, j, iguales;
    int tieneTercia = 0, tienePar = 0;
    int suma = 0;
    for (i = 0; i < tamano; i++) {
        suma += numeros[i];
    }

    for (i = 0; i < tamano; i++) {
        iguales = 1;
        for (j = 0; j < tamano; j++) {
            if (i != j && numeros[i] == numeros[j]) {
                iguales++;
            }
        }
        if (iguales == 3)
            tieneTercia = 1;
        if (iguales == 2)
            tienePar = 1;
    }

    if (tieneTercia && tienePar)
        return suma;
    else
        return 0;
}

// 1)
/*
 * Suma los valores del vector si todos los elementos son iguales.
 * Si no son todos iguales, devuelve 0.
 * numeros: vector de enteros
 * tamaño: cantidad de elementos en el vector
 * retorna: suma de los valores si todos son iguales, 0 si no
 */
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

// 2)
/*
 * Suma los valores de un número que aparece al menos 3 veces en el vector.
 * Si no hay ningún número repetido 3 o más veces, devuelve 0.
 * numeros: vector de enteros
 * tamaño: cantidad de elementos en el vector
 * retorna: suma de los valores repetidos 3 o más veces
 */
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
            return suma;
        }
    }
    return 0;
}

// 3)
/*
 * Suma los valores de un número que aparece al menos 2 veces en el vector.
 * Si no hay ningún número repetido 2 o más veces, devuelve 0.
 */
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

// 4)
/*
 * Suma los valores si los números forman una secuencia consecutiva.
 * Si no forman secuencia, devuelve 0.
 */
int sumaSiSecuenciaVectores(int numeros[], int tamaño) {
    // Ordenamiento burbuja
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
        if (numeros[i] != numeros[i - 1] + 1)
            return 0;
    }
    int suma = 0;
    for (int i = 0; i < tamaño; i++)
        suma += numeros[i];
    return suma;
}

// 5)
/*
 * Comprueba si el vector forma un Full House (3 iguales + 2 iguales)
 * Retorna la suma total si es Full House, 0 si no.
 */
int fullHouse(int numeros[], int tamano) {
    int i, j, iguales;
    int tieneTercia = 0, tienePar = 0;
    int suma = 0;

    for (i = 0; i < tamano; i++)
        suma += numeros[i];

    for (i = 0; i < tamano; i++) {
        iguales = 1;
        for (j = 0; j < tamano; j++) {
            if (i != j && numeros[i] == numeros[j])
                iguales++;
        }
        if (iguales == 3) tieneTercia = 1;
        if (iguales == 2) tienePar = 1;
    }

    if (tieneTercia && tienePar)
        return suma;
    else
        return 0;
}

// 6 a 11)
/*
 * Suma los valores de un número específico (1 a 6) en el vector.
 * numeros: vector de enteros
 * tamano: cantidad de elementos
 * retorna: suma de los valores que coinciden con el número específico
 */
int sumaDeUnosVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 1)
            suma += 1;
    return suma;
}

int sumaDeDosVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 2)
            suma += 2;
    return suma;
}

int sumaDeTresVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 3)
            suma += 3;
    return suma;
}

int sumaDeCuatrosVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 4)
            suma += 4;
    return suma;
}

int sumaDeCincoVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 5)
            suma += 5;
    return suma;
}

int sumaDeSeisVectores(int numeros[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++)
        if (numeros[i] == 6)
            suma += 6;
    return suma;
}

// 12)
/*
 * Verifica si los números forman una secuencia baja (1 a 5 consecutivos)
 * Retorna 1 si es secuencia baja, 0 si no.
 */
int esSecuenciaBajaVectores(int numeros[], int tamaño) {
    // Ordenamiento burbuja
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    if (numeros[0] != 1 || numeros[tamaño - 1] != 5)
        return 0;
    for (int i = 1; i < tamaño; i++)
        if (numeros[i] != numeros[i - 1] + 1)
            return 0;
    return 1;
}

// 13)
/*
 * Verifica si los números forman una secuencia alta (2 a 6 consecutivos)
 * Retorna 1 si es secuencia alta, 0 si no.
 */
int esSecuenciaAltaVectores(int numeros[], int tamaño) {
    // Ordenamiento burbuja
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    if (numeros[0] != 2 || numeros[tamaño - 1] != 6)
        return 0;
    for (int i = 1; i < tamaño; i++)
        if (numeros[i] != numeros[i - 1] + 1)
            return 0;
    return 1;
}

#include <stdio.h>
#include "aleatorio.h"

int main() {
    initAleatorio();
    int prediccionDado;
    int resultadoDado;
    printf("Que numero crees que caera el dado(1-6)?\n");
    scanf("%d", &prediccionDado);
    resultadoDado = lanzarDado();
    printf("El dado cayo en %d\n", resultadoDado);

    if (prediccionDado == resultadoDado) {
        printf("Acertaste el dado, felicidades!!\n");
    } else {
        printf("Fallaste:(");
    }

    return 0;
}
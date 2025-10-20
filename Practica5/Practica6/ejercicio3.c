#include <stdio.h>
#include "aleatorio.h"
#include "dados.h"

int main() {
initAleatorio();

    int dados[5];
    char opcion;
    int intento = 1;


    tirarDados(dados, 5);
    printf("Primer lanzamiento:\n");
    mostrarDados(dados, 5);

    while (intento < 3) {
        printf("Quieres volver a lanzar algun dado? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            relanzarDados(dados, 5);

            printf("Resultados despues del lanzamiento %d:\n", intento + 1);
            mostrarDados(dados, 5);
        }

        intento++;
    }

    printf("\nResultados finales:\n");
    mostrarDados(dados, 5);

    return 0;
}

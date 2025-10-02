#include <stdio.h>
#include <stdbool.h>

void MenuCombinaciones() {
  printf("  -- MENU ---\n");
  printf("1. Lanzar 5 dados\n");
  printf("2. Mostrar dados\n");
  printf("3. Balut\n");
  printf("4. Secuencia\n");
  printf("7. Terminar\n");
}




// 1) Funcion que recibe los 5 dados que mediante un ciclo if los compara para verificar
//si son iguales y Regresa la suma de los 5 numeros iguales, si no regresa 0
int sumaSiIguales(int d1, int d2, int d3, int d4, int d5) {
  if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) {
int suma = d1 + d2 + d3 + d4 + d5;
   return suma;
 } else {
   return 0;
 }
}


//2)
int sumaTresIguales(int d1, int d2, int d3, int d4, int d5) {
  if (d1 == d2 && d1 == d3)
    return d1 + d2 + d3;
  if (d1 == d2 && d1 == d4)
    return d1 + d2 + d4;
  if (d1 == d2 && d1 == d5)
    return d1 + d2 + d5;
  if (d1 == d3 && d1 == d4)
    return d1 + d3 + d4;
  if (d1 == d3 && d1 == d5)
    return d1 + d3 + d5;
  if (d1 == d4 && d1 == d5)
    return d1 + d4 + d5;
  if (d2 == d3 && d2 == d4)
    return d2 + d3 + d4;
  if (d2 == d3 && d2 == d5)
    return d2 + d3 + d5;
  if (d2 == d4 && d2 == d5)
    return d2 + d4 + d5;
  if (d3 == d4 && d3 == d5)
    return d3 + d4 + d5;
  return 0;
}


// 3) Funcion que recibe los 5 dados que mediante c
// Regresa la suma si hay al menos dos iguales, si no regresa 0
int sumaDosIguales(int d1, int d2, int d3, int d4, int d5) {
 if (d1 == d2)
   return d1 + d2;
 if (d1 == d3)
   return d1 + d3;
 if (d1 == d4)
   return d1 + d4;
 if (d1 == d5)
   return d1 + d5;
 if (d2 == d3)
   return d2 + d3;
 if (d2 == d4)
   return d2 + d4;
 if (d2 == d5)
   return d2 + d5;
 if (d3 == d4)
   return d3 + d4;
 if (d3 == d5)
   return d3 + d5;
 if (d4 == d5)
   return d4 + d5;
 return 0;
}

//4)
int sumaSiEsSecuencia(int a, int b, int c, int d, int e) {
  if (b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1) {
    return a + b + c + d + e;
  }
  return 0;
}







//5)









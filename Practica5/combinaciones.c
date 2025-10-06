#include <stdio.h>




void MenuCombinaciones() {
 printf("  -- MENU ---\n");
 printf("1. Lanzar 5 dados\n");
 printf("2. Mostrar dados\n");
 printf("3. Balut\n");
 printf("4. Full House\n");
 printf("5. Secuencia baja (1-5)\n");
 printf("6. Secuencia alta (2-6)\n");
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




// 3) Funcion que recibe los 5 dados que mediante ciclos if para
//comparar 2 dados con todas sus posibles combinaciones,
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



//5)
int sumaSiHayFullHouse(int d1, int d2, int d3, int d4, int d5) {
int suma = d1 + d2 + d3 + d4 + d5;


if ((d1 == d2 && d1 == d3 && d4 == d5 && d4 != d1) ||
 (d1 == d2 && d1 == d4 && d3 == d5 && d3 != d1) ||
 (d1 == d2 && d1 == d5 && d3 == d4 && d3 != d1) ||
 (d1 == d3 && d1 == d4 && d2 == d5 && d2 != d1) ||
 (d1 == d3 && d1 == d5 && d2 == d4 && d2 != d1) ||
 (d1 == d4 && d1 == d5 && d2 == d3 && d2 != d1) ||
 (d2 == d3 && d2 == d4 && d1 == d5 && d1 != d2) ||
 (d2 == d3 && d2 == d5 && d1 == d4 && d1 != d2) ||
 (d2 == d4 && d2 == d5 && d1 == d3 && d1 != d2) ||
 (d3 == d4 && d3 == d5 && d1 == d2 && d1 != d3)) {
 return suma;
 } else {
   return 0;
 }
}


int esSecuenciaBaja(int d1, int d2, int d3, int d4, int d5) {
 int temp;

 if (d1 > d2) {
   temp = d1;
   d1 = d2;
   d2 = temp;
 }
 if (d1 > d3) {
   temp = d1;
   d1 = d3;
   d3 = temp;
 }
 if (d1 > d4) {
   temp = d1;
   d1 = d4;
   d4 = temp;
 }
 if (d1 > d5) {
   temp = d1;
   d1 = d5;
   d5 = temp;
 }
 if (d2 > d3) {
   temp = d2;
   d2 = d3;
   d3 = temp;
 }
 if (d2 > d4) {
   temp = d2;
   d2 = d4;
   d4 = temp;
 }
 if (d2 > d5) {
   temp = d2;
   d2 = d5;
   d5 = temp;
 }
 if (d3 > d4) {
   temp = d3;
   d3 = d4;
   d4 = temp;
 }
 if (d3 > d5) {
   temp = d3;
   d3 = d5;
   d5 = temp;
 }
 if (d4 > d5) {
   temp = d4;
   d4 = d5;
   d5 = temp;
 }


 // Verificar que cada dado sea 1 mayor que el anterior
 if (d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1 && d5 == d4 + 1 && d1 == 1)
   return 15; // Secuencia 1-5
 else
   return 0;
}

int esSecuenciaAlta(int d1, int d2, int d3, int d4, int d5) {
  int temp;

  // Ordenar
  if (d1 > d2) {
    temp = d1;
    d1 = d2;
    d2 = temp;
  }
  if (d1 > d3) {
    temp = d1;
    d1 = d3;
    d3 = temp;
  }
  if (d1 > d4) {
    temp = d1;
    d1 = d4;
    d4 = temp;
  }
  if (d1 > d5) {
    temp = d1;
    d1 = d5;
    d5 = temp;
  }
  if (d2 > d3) {
    temp = d2;
    d2 = d3;
    d3 = temp;
  }
  if (d2 > d4) {
    temp = d2;
    d2 = d4;
    d4 = temp;
  }
  if (d2 > d5) {
    temp = d2;
    d2 = d5;
    d5 = temp;
  }
  if (d3 > d4) {
    temp = d3;
    d3 = d4;
    d4 = temp;
  }
  if (d3 > d5) {
    temp = d3;
    d3 = d5;
    d5 = temp;
  }
  if (d4 > d5) {
    temp = d4;
    d4 = d5;
    d5 = temp;
  }

  // Verificar secuencia consecutiva iniciando en 2
  if (d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1 && d5 == d4 + 1 && d1 == 2)
    return 20;  // Secuencia 2-6
  else
    return 0;
}


//6)
int sumaDeUno(int d1, int d2, int d3, int d4, int d5) {
int suma = 0;

if (d1 == 1)
 suma = suma+1;
if (d2 == 1)
 suma = suma+1;
if (d3 == 1)
 suma = suma+1;
if (d4 == 1)
 suma = suma+1;
if (d5 == 1)
 suma = suma+1;

return suma; // si no hay ningun 2, suma seguirá siendo 0
}

//7
int sumaDeDos(int d1, int d2, int d3, int d4, int d5) {
 int suma = 0;

 if (d1 == 2)
   suma = suma+2;
 if (d2 == 2)
   suma = suma+2;
 if (d3 == 2)
   suma = suma+2;
 if (d4 == 2)
   suma = suma+2;
 if (d5 == 2)
   suma = suma+2;

 return suma; // si no hay ningun 2, suma seguirá siendo 0
}


//8)
int sumaDeTres(int d1, int d2, int d3, int d4, int d5) {
 int suma = 0;

 if (d1 == 3)
   suma = suma+3;
 if (d2 == 3)
   suma = suma+3;
 if (d3 == 3)
   suma = suma+3;
 if (d4 == 3)
   suma = suma+3;
 if (d5 == 3)
   suma = suma+3;

 return suma; // si no hay ningun 3, suma seguirá siendo 0
}




int sumaDeCuatro(int d1, int d2, int d3, int d4, int d5) {
 int suma = 0;

 if (d1 == 4)
   suma = suma+4;
 if (d2 == 4)
   suma = suma+4;
 if (d3 == 4)
   suma = suma+4;
 if (d4 == 4)
   suma = suma+4;
 if (d5 == 4)
   suma = suma+4;

 return suma;
}




int sumaDeCinco(int d1, int d2, int d3, int d4, int d5) {
 int suma = 0;

 if (d1 == 5)
   suma = suma+5;
 if (d2 == 5)
   suma = suma+5;
 if (d3 == 5)
   suma = suma+5;
 if (d4 == 5)
   suma = suma+5;
 if (d5 == 5)
   suma = suma+5;

 return suma;
}




int sumaDeSeis(int d1, int d2, int d3, int d4, int d5) {
 int suma = 0;

 if (d1 == 6)
   suma = suma+6;
 if (d2 == 6)
   suma = suma+6;
 if (d3 == 6)
   suma = suma+6;
 if (d4 == 6)
   suma = suma+6;
 if (d5 == 6)
   suma = suma+6;

 return suma;
}

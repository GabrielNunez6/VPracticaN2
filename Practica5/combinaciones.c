// 1) Regresa la suma si los 5 números son iguales, si no regresa 0
int sumaSiIguales(int d1, int d2, int d3, int d4, int d5) {
 if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) {
   return d1 + d2 + d3 + d4 + d5;
 }
 return 0;
}


// 2) Regresa la suma si exactamente tres son iguales, si no regresa 0
int sumaTresIguales(int d1, int d2, int d3, int d4, int d5) {
 if (d1 == d2 && d1 == d3 && d1 != d4 && d1 != d5)
   return d1*3;
 if (d1 == d2 && d1 == d4 && d1 != d3 && d1 != d5)
   return d1*3;
 if (d1 == d2 && d1 == d5 && d1 != d3 && d1 != d4)
   return d1*3;
 if (d1 == d3 && d1 == d4 && d1 != d2 && d1 != d5)
   return d1*3;
 if (d1 == d3 && d1 == d5 && d1 != d2 && d1 != d4)
   return d1*3;
 if (d1 == d4 && d1 == d5 && d1 != d2 && d1 != d3)
   return d1*3;
 if (d2 == d3 && d2 == d4 && d2 != d1 && d2 != d5)
   return d2*3;
 if (d2 == d3 && d2 == d5 && d2 != d1 && d2 != d4)
   return d2*3;
 if (d2 == d4 && d2 == d5 && d2 != d1 && d2 != d3)
   return d2*3;
 if (d3 == d4 && d3 == d5 && d3 != d1 && d3 != d2) return d3*3;
 return 0;
}


// 3) Regresa la suma si hay al menos dos iguales, si no regresa 0
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


// 4) Regresa la suma si forman una secuencia consecutiva
int sumaSiSecuencia(int d1, int d2, int d3, int d4, int d5) {
 int temp;
 if (d1 > d2) {
   temp=d1;
   d1=d2;
   d2=temp;
 }
 if (d1 > d3) {
   temp=d1;
   d1=d3;
   d3=temp;
 }
 if (d1 > d4) {
   temp=d1;
   d1=d4;
   d4=temp;
 }
 if (d1 > d5) {
   temp=d1;
   d1=d5;
   d5=temp;
 }
 if (d2 > d3) {
   temp=d2;
   d2=d3;
   d3=temp;
 }
 if (d2 > d4) {
   temp=d2;
   d2=d4;
   d4=temp;
 }
 if (d2 > d5) {
   temp=d2;
   d2=d5;
   d5=temp;
 }
 if (d3 > d4) {
   temp=d3;
   d3=d4;
   d4=temp;
 }
 if (d3 > d5) {
   temp=d3;
   d3=d5;
   d5=temp;
 }
 if (d4 > d5) {
   temp=d4;
   d4=d5;
   d5=temp;
 }


 if (d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1 && d5 == d4 + 1) {
   return d1 + d2 + d3 + d4 + d5;
 }
 return 0;
}

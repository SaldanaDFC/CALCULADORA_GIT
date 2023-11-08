#include<stdio.h>
#include "ojitos.h"
//FACTORIAL
int factorial(int a){
  int i, f;
  f=1;
  for(i=1;i<=a;i++){
     f=f*i;
  }
  return f;
}
//FACTORIAL RECURSIVO
int factorial_rec(int a){
  int fr;
  if(a == 0){
    return 1;
  }
  else{
    fr=factorial_rec(a-1);
    return a*fr;
  }
}
//FIBONACCI
void triangulo_fib(int tam){
 int i, j;
 int fib;
 printf("Triangulo serie de fibonacci\n");
 fib=serie_fib(tam);
 for(i=-1;i<tam;i++){
     printf("\n");
     for(j=0; j<=i+1;j++){
	printf("%i",serie_fib(j));
     }
 }
printf("\nEl numero en f(%i) es %i\n",tam, fib);
}
int serie_fib(int val_final){
    int i, j;
    int f=0;
    int f2=0;
    int f1=0;
    for(i=0;i<val_final;i++){
      if(i==1){
	f=1;
      }
      f1=f;
      f=f1+f2;			       
      f2=f1;
     }
    if(i==1) return i;
    else return f;
}
